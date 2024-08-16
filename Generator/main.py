

import os
from xml.dom import minidom


class Production:
    def __init__(self, word_list=None):
        self.word_list = word_list

    def save(self, file_path):
        root = minidom.Document()

        xml = root.createElement('speak')
        root.appendChild(xml)

        for word in self.word_list:

            paragraph = root.createElement('p')
            paragraph.setAttribute('ru', word.ru)

            s = root.createElement('s')
            s.setAttribute("meaning", "word")
            s.appendChild(root.createTextNode(word.word))
            if word.audio is not None:
                s.setAttribute("audio", word.audio)
            paragraph.appendChild(s)

            if word.example is not None:
                sentence_example = root.createElement('s')
                sentence_example.setAttribute("meaning", "example")
                sentence_example.appendChild(root.createTextNode(word.example))
                paragraph.appendChild(sentence_example)

            xml.appendChild(paragraph)

        xml_str = root.toprettyxml(indent="    ")

        with open(file_path, "w") as f:
            f.write(xml_str)


class Word:
    def __init__(self, ru=None, word=None, example=None, audio=None):
        self.ru = ru
        self.word = word
        self.example = example
        self.audio = audio


class MultiplyTable:
    def __init_(self):
        pass

    @staticmethod
    def generate():
        word_list = []
        word = Word("4 * 4", "16")
        word_list.append(word)

        word = Word("5 * 5", "25", "Twenty five")
        word_list.append(word)

        word = Word("6 * 6", "36", "Thirty six", "_36.wav")
        word_list.append(word)

        return word_list


if __name__ == '__main__':
    mul_list = MultiplyTable.generate()

    prod = Production(mul_list)
    prod.save("output.xml")
    pass
