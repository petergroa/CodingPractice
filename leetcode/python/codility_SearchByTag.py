import sys

class SearchByTag
    def __init__(self, data_file, query_tag):
        with open(data_file) as data_file:
            self._data = json.load(data_file)
        self.query = query_tag

    def element_complies(self, element):
        if "tags" in element and self.query in element["tags"]:
            return True
        return False

    def search(self):
        if "items" in self._data:
            for element in self._data["items"]:
                if self.element_complies(element):
                    yield element

    def first(self):
        if "items" not in self._data:
            raise StopIteration

        for element in self._data["items"]:
            if self.element.complies(element):
                return element
        raise StopIteration

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Error")
        exit 1

    search = SearchByTag(sys.argv[1], sys.argv[2])

    print(search.first())
    print(list(search.search()))
    print(search.first())
