/* Quick script to test some promises behavior
 */
function getRandomInt(max) {
  return Math.floor(Math.random() * max);
}

const performanceCheck = (name, fun) => {
  const start = performance.now();
  fun(name);
  console.log(`${name}: ${performance.now() - start} miliseconds`);
}

const asyncPerformanceCheck = async (name, fun) => {
  const start = performance.now();
  try {
    await fun(name);
    console.log(`${name}: ${performance.now() - start} miliseconds`);
  } catch (e) {
    console.error(`${name} (ded) - ${performance.now()-start} miliseconds`, e);
  }
}

let start = performance.now()

const p = (prob) => {
  return new Promise((resolve, reject) => {
    let ran = getRandomInt(100);
    setTimeout(() => {
      (ran < prob)? resolve(ran) : reject(ran);
    }, ran);
  });
}

const a1 = async (name, fail = false) => {
  console.log(`${name} - Called A1`);
  if (fail) throw new Error(`${name}! Failed`);

  return p(50)
    .then(result => { console.log(`${name} - a1`, result); return result; })
    .catch(err => { console.error(`${name} - ea1`, err); throw err; })
};

const a2 = async (name, fail = false) => {
  console.log(`${name} - Called A2`);
  // 50% chance to return a 0
  if (getRandomInt(100) < 10) return 0;

  return a1(name, fail = fail)
    .then(function a2_then(val){
      console.log(`${name} - a2`, val);
      return val;
    })
    .catch(function a2_catch(err){
      console.error(`${name} - ea2`, err);
      throw err;
    })
};

const a3 = async (name, fail = false) => {
  console.log(`${name} - Called A3`);
  let a2_res = await a2(name, fail = fail)
    .catch(function a3_catch(err){ console.error(`${name} - ea3`, err); })
  console.log(`${name} - a3 => a2_res=${a2_res}`);
};

const awaitedP = async (name, fail = false) => {
  return new Promise(async (resolve, reject) => {
    let p = await a3(name, fail);
    console.log(`Waited for value ${p}`);
    resolve(p);
  });
}

// TODO: Check memory usage
console.log(`Declaration time check: ${performance.now()-start} miliseconds`);

/* =========================================================================== */
for(let i = 0 ; i < 6 ; i++) {
  setTimeout(() => {
    asyncPerformanceCheck(`#${i}`, a3);
  }, getRandomInt(5000));
}
// */

/* =========================================================================== *
setTimeout(() => {
  asyncPerformanceCheck("Await in Promise", async (name) => { await awaitedP(name);});
}, getRandomInt(5000));
// */
