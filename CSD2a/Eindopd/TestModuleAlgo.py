import time
import numpy as np


def split_note(notes, index, random_range):
    if(index >= len(notes) - 1): return

    split_amount = np.random.choice([0.75, 0.5, 1], p = [0.450, 0.450, 0.10])

    dur = notes[index]
    new_dur = dur * split_amount
    rest_dur = dur - new_dur
    notes[index] = new_dur
    notes.insert(index +1, rest_dur)
