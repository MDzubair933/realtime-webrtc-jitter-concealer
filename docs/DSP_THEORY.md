# Packet Loss Concealment (PLC) DSP Theory

When voice packets are dropped over UDP networks:
1. Short drops (<40ms): Extrapolate speech waveform using LPC autocorrelation coefficients.
2. Long drops (>80ms): Gracefully attenuate frame amplitude to background comfort noise level.
