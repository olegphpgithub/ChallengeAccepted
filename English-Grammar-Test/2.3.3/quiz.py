#!/usr/bin/env python3
"""Console English grammar quiz based on level0.json."""

import json
import random
import sys
from pathlib import Path

QUESTIONS_FILE = Path(__file__).with_name("level0.json")


def load_questions(path):
    """Load the list of questions from a JSON file."""
    with open(path, encoding="utf-8") as f:
        return json.load(f)


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
    questions = load_questions(QUESTIONS_FILE)
    if not questions:
        print("No questions found.")
        return

    correct = 0
    wrong = 0
    pool = []  # ids that have not been asked yet in the current round

    try:
        while True:
            # 1. Pick a random question (no repeats until all have been asked)
            if not pool:
                pool = list(range(len(questions)))
            q = questions[pool.pop(random.randrange(len(pool)))]

            # 2. Show the task
            print("\n" + "=" * 60)
            print(f"Question #{q['id']}: {q['task']}\n")

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

            # 7. Show the score and go to the next question
            print(f"\nScore: correct {correct}, wrong {wrong}")
            input("Press Enter to continue...")
    except (KeyboardInterrupt, EOFError):
        print()

    total = correct + wrong
    print(f"\nFinal score: correct {correct}, wrong {wrong}, total {total}.")


if __name__ == "__main__":
    sys.exit(main())
