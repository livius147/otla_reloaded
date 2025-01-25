# otla_reloaded
The original source of the OTLA project has been ported to be compiled and to be run under Linux console

# Usage
Usage:
./otla [options] -p <ZXS|CPC|MSX|81-\> -i <filename\>             
  OPTIONS:                             
  -pol <1|-1>                          Inverse wav polarity (default: 1)

  -form <0|1|2|3|4|5|6>                Waveform (default: 1 i.e. Cubic)
                                       0: Square
                                       1: Cubic
                                       2: SqrSin
                                       3: Shaw
                                       4: E=cte
                                       5: Delta
                                       6: Delta2

  -freq <44100|48000>                  Sampling frequency (default: 44100)

  -spb <17|16|15|14|12|10|11|8|7>      Samples per bit
                                       (default: 14 i.e. 3.75)
                                       17: 4.25
                                       16: 4.0
                                       15: 3.75
                                       14: 3.50
                                       12: 3.0
                                       10: 2.50
                                       11: 2.75
                                       8:  2.25
                                       7:  1.75

  -acc <0|1>                           Accelerate (default: 0)

  -pause <ms>                          Pause between blocks (default: 500)

  -loader <0|1>                        Make loader (default: 1)

  -check <0|1>                         Check loading error (default: 1)

  -int <0|1>                           Enable interrupts (default: 0)

  -nosbb                               Remove SBB file

  -nowav                               Remove WAV file

  -mp3                                 Convert to mp3 (lame is needed)

