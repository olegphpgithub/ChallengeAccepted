#!/usr/bin/env python3
"""Console English grammar quiz based on level0.json.

Usage:
    python quiz.py                  # all questions
    python quiz.py --range=101,120  # questions 101..120 (inclusive)
    python quiz.py --group=2        # group 2 of 20 questions (21..40)

Question numbers are 1-based positions in the JSON file.
"""

import argparse
import json
import random
import sys
from pathlib import Path

QUESTIONS_FILE = Path(__file__).with_name("level0.json")
GROUP_SIZE = 20


def load_questions(path):
    """Load the list of questions from a JSON file."""
    with open(path, encoding="utf-8") as f:
        return json.load(f)


def parse_range(value):
    """Parse 'START,END' into a tuple of two ints."""
    try:
        start, end = (int(x) for x in value.split(","))
    except ValueError:
        raise argparse.ArgumentTypeError("expected format: --range=START,END (e.g. --range=101,120)")
    return start, end


def parse_args():
    parser = argparse.ArgumentParser(description="English grammar quiz")
    # --range and --group cannot be used together
    mode = parser.add_mutually_exclusive_group()
    mode.add_argument("--range", dest="q_range", type=parse_range, metavar="START,END",
                      help="ask only questions START..END (inclusive), e.g. --range=101,120")
    mode.add_argument("--group", type=int, metavar="N",
                      help=f"split questions into groups of {GROUP_SIZE} and ask only group N")
    return parser.parse_args()


def select_questions(questions, args, parser_error):
    """Return a list of (number, question) pairs according to the arguments."""
    total = len(questions)
    numbered = list(enumerate(questions, start=1))

    if args.q_range is not None:
        start, end = args.q_range
        if start < 1 or end > total or start > end:
            parser_error(f"--range must satisfy 1 <= START <= END <= {total}")
        return numbered[start - 1:end]

    if args.group is not None:
        groups_count = (total + GROUP_SIZE - 1) // GROUP_SIZE
        if not 1 <= args.group <= groups_count:
            parser_error(f"--group must be between 1 and {groups_count}")
        start = (args.group - 1) * GROUP_SIZE
        return numbered[start:start + GROUP_SIZE]

    return numbered


def ask_choice(options_count):
    """Ask the user for a number from 1 to options_count. Return None on quit."""
    while True:
        raw = input(f"Your answer (1-{options_count}, q to quit): ").strip().lower()
        if raw in ("q", "quit", "exit"):
            return None
        if raw.isdigit() and 1 <= int(raw) <= options_count:
            return int(raw)
        print(f"Please enter a number from 1 to {options_count}.")


def main():
    parser = argparse.ArgumentParser()  # only used for error reporting below
    args = parse_args()
    questions = load_questions(QUESTIONS_FILE)
    selected = select_questions(questions, args, parser.error)
    if not selected:
        print("No questions found.")
        return

    total = len(selected)
    correct = 0
    wrong = 0
    # Questions not asked yet; asked ones are removed, so none repeats
    pool = list(selected)

    try:
        while pool:
            # 1. Pick a random question that has not been asked yet
            number, q = pool.pop(random.randrange(len(pool)))

            # 2. Show the task
            print("\n" + "=" * 60)
            print(f"Question {number} (id {q['id']}): {q['task']}\n")

            # 3. Show the 4 answer options
            for i, option in enumerate(q["vars"], start=1):
                print(f"  {i}) {option}")
            print()

            # 4. Get the user's answer
            choice = ask_choice(len(q["vars"]))
            if choice is None:
                break

            # 5. Check the answer ("answer" is 1-based)
            right = q["answer"]
            if choice == right:
                correct += 1
                print("\n✔ Correct!")
            else:
                wrong += 1
                print("\n✘ Wrong.")
            print(f"Right answer: {right}) {q['vars'][right - 1]}")

            # 6. Show the explanation
            print(f"\nExplanation: {q['explanation']}")

            # 7. Show the score and progress
            done = correct + wrong
            print(f"\nScore: correct {correct}, wrong {wrong}")
            print(f"Progress: {done} of {total} questions done, {total - done} left")
            if pool:
                input("Press Enter to continue...")
    except (KeyboardInterrupt, EOFError):
        print()

    done = correct + wrong
    print("\n" + "=" * 60)
    print(f"Finished. Questions done: {done} of {total}.")
    print(f"Final score: correct {correct}, wrong {wrong}.")


if __name__ == "__main__":
    sys.exit(main())
