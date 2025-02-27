import argparse
import os

# Needs sudo
#from keyboard import wait, add_hotkey
from typing import Generator
from pynput import keyboard

MAX_DEPTH = 3

class Graph:
    _nodes:dict[str, dict[str, int]]

    def __init__(self, logs:tuple[str]=()) -> None:
        print("Creating Graph...")
        self._nodes = dict()

        if not isinstance(logs, tuple):
            raise ValueError("logs is not an instance of tuple")
        # add starting logs
        for log in logs:
            if not isinstance(log, str):
                raise ValueError(f"{log} is not an instance of str")
            self.add(log)

    def add(self, value:str) -> int:
        if value.endswith('\n'):
            value = value[:-1]

        print(f"Adding {value}")
        values = value.split(' ')

        # Add first value
        # Distribute weights on the rest
        cur_node = None
        while values:
            value = values.pop(0)

            # Set to nodes list
            if value not in self._nodes:
                self._nodes[value] = dict()

            if cur_node is not None:
                if value in self._nodes[cur_node]:
                    self._nodes[cur_node][value] += 1
                else:
                    self._nodes[cur_node][value] = 1

            # Set as the current node
            cur_node = value

    def suggest(self, word:str, cur_node:str=None, curr_depth:int=0) -> Generator[str, None, None]:
        if word not in self._nodes:
            raise StopIteration()

        if curr_depth > MAX_DEPTH:
            return

        for w, weight in self._nodes[word].items():
            wor = f"{word} {self.suggest(w, word, curr_depth+1)}"
            print(f"S({word}){wor}", end=' ')
            return wor
#            yield f"{word} {self.suggest(w, word, curr_depth+1)}"

def give_suggestion(graph:Graph, word:str):
    try:
        print(f"?: {graph.suggest(word)}")
    except StopIteration:
        print("No more suggestions")

def main(args: argparse.Namespace) -> int:
    if not isinstance(args.log_file, str):
        raise ValueError(f"{args.log_file} is not a string!")

    if not os.path.isfile(args.log_file):
        raise ValueError(f"{args.log_file} is not a correct file path!")

    if args.log_file.split('.')[-1] != "txt":
        raise ValueError(f"{args.log_file} is not in an accepted format!")

    graph = Graph()
    with open(args.log_file) as logs:
        for log in logs:
            graph.add(log)

    words = list()
    inp = input()
    words.append(inp)
    while inp != "exit":
        """
        needs sudo
        while True:
            add_hotkey(' ', lambda: words.append(give_suggestion(graph, inp)))
            add_hotkey('tab', lambda: give_suggestion(graph, inp))
            add_hotkey('del', lambda: words)

            wait('enter')
            break
        """
            
        graph.add(inp)
        inp = input()
        
        index = 0
        for c in inp:
            if c != ' ':
                break
            index += 1
        inp = inp[index:]

    return 0

if __name__ == "__main__":
    parser = argparse.ArgumentParser (
        prog = "Search suggestion",
        description = ""
    )
    parser.add_argument("log_file", type=str,
        help = ""
    )
    exit(main(parser.parse_args()))
