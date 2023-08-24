import os
import re
import mysql.connector
from datetime import datetime

from local_settings import *

BASE_DIR = os.path.dirname(os.path.abspath(__file__))
INPUT_FILE = r'd:\nnRus.Git\ChallengeAccepted\learn\024_learn.txt'
OUTPUT_FILE = r'd:\nnRus.Git\ChallengeAccepted\learn\024_learn.xml'


with open(INPUT_FILE, 'rb') as input_h:
    content = input_h.read()
    file_lines = content.split(b"\n")
    with open(OUTPUT_FILE, 'wb') as output_h:
        output_h.write(b"<speak>\r\n")
        for file_line in file_lines:
            line = file_line.decode("UTF-8")
            m = re.search(r'(.+)->(.+)', line)
            if m is not None:

                output_h.write(b"    <p ru=\"")
                output_h.write(str.encode(m.group(2)).strip())
                output_h.write(b"\">\r\n")

                ddd = "        <s meaning=\"word\">%s</s><break time=\"2000ms\"/>\r\n" % m.group(1)
                output_h.write(str.encode(ddd))
                output_h.write(str.encode("        <s meaning=\"example\"></s><break time=\"1000ms\"/>\r\n"))
                output_h.write(str.encode("        <!---->\r\n"))
                output_h.write(str.encode("        <s></s><break time=\"1000ms\"/>\r\n"))
                output_h.write(str.encode("        <s></s><break time=\"1000ms\"/>\r\n"))

                output_h.write(b"    </p>\r\n")
        output_h.write(b"</speak>")

