# daisy-audio-delay

This is simple code for a Daisy Pod that passes through audio with a slight delay, adjustable by the potentiometer 1 on the board.

It solves a small but annoying problem: Our home DJ setup main speakers have a delay of around 25ms between what you hear in the main speakers relative to what you hear in the headphones. This means that if you beatmatch a new track in the heaadphones, then bring it up on the main speakers, it will be noticeably off. About 15ms of the delay is due to the speakers being about 15ft from the controller, and about 10ms is I suspect due to the speakers having some DSP in them. By putting this delay on the headphones line, we delay that signal by a matching amount, so beatmatching in the headphones will mean matched beats out of the main speakers.
