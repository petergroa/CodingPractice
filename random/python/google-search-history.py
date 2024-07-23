import sys
import json

from typing import Generator

HISTORY_LAN = "es"

SEARCH_TAGS = ("Google Search", "Buscar con Google")

def search_history(file_path:str) -> Generator[str, None, None]:
    with open(file_path) as fp:
        history = json.load(fp)
        for entry in history["Browser History"]:
            # Decomposition of title
            title_dec = entry["title"].split(" - ")
            if title_dec[-1] in SEARCH_TAGS:
                if len(title_dec) > 2:
                    yield " - ".join(title_dec[:-1])
                else:
                    yield title_dec[0]

def main(file_path:str, output_path:str) -> int:
#    for search in search_history(file_path):
#        print(search)
    with open(output_path, "a") as out:
        for search in search_history(file_path):
            out.write(search+"\n")
    return 0

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Must only receive the .json file of Chrome's history and the output path!",
              file=sys.stderr)

    exit(main(sys.argv[1], sys.argv[2]))
