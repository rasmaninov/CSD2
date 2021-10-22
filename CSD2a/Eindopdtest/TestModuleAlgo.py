
import numpy as np


def split_note(notes, index, random_range):
    if(index >= len(notes) - 1): return

    split_amount = np.random.choice([0.5, .25], p = [0.5, 0.5])

    dur = notes[index]

    new_dur = dur * split_amount

    rest_dur = dur - new_dur

    notes[index] = new_dur

    notes.insert(index +1, rest_dur)
