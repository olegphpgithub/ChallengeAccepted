ffmpeg -i "concat:set/03.mp3|set/times.mp3|set/02.mp3" -acodec copy 03_02.mp3
ffmpeg -i "concat:set/03.mp3|set/times.mp3|set/03.mp3" -acodec copy 03_03.mp3
ffmpeg -i "concat:set/03.mp3|set/times.mp3|set/04.mp3" -acodec copy 03_04.mp3
ffmpeg -i "concat:set/03.mp3|set/times.mp3|set/05.mp3" -acodec copy 03_05.mp3
ffmpeg -i "concat:set/03.mp3|set/times.mp3|set/06.mp3" -acodec copy 03_06.mp3
ffmpeg -i "concat:set/03.mp3|set/times.mp3|set/07.mp3" -acodec copy 03_07.mp3
ffmpeg -i "concat:set/03.mp3|set/times.mp3|set/08.mp3" -acodec copy 03_08.mp3
ffmpeg -i "concat:set/03.mp3|set/times.mp3|set/09.mp3" -acodec copy 03_09.mp3
ffmpeg -i "concat:set/04.mp3|set/times.mp3|set/04.mp3" -acodec copy 04_04.mp3
ffmpeg -i "concat:set/04.mp3|set/times.mp3|set/05.mp3" -acodec copy 04_05.mp3
ffmpeg -i "concat:set/04.mp3|set/times.mp3|set/06.mp3" -acodec copy 04_06.mp3
ffmpeg -i "concat:set/04.mp3|set/times.mp3|set/07.mp3" -acodec copy 04_07.mp3
ffmpeg -i "concat:set/04.mp3|set/times.mp3|set/08.mp3" -acodec copy 04_08.mp3
ffmpeg -i "concat:set/04.mp3|set/times.mp3|set/09.mp3" -acodec copy 04_09.mp3
ffmpeg -i "concat:set/05.mp3|set/times.mp3|set/05.mp3" -acodec copy 05_05.mp3
ffmpeg -i "concat:set/05.mp3|set/times.mp3|set/06.mp3" -acodec copy 05_06.mp3
ffmpeg -i "concat:set/05.mp3|set/times.mp3|set/07.mp3" -acodec copy 05_07.mp3
ffmpeg -i "concat:set/05.mp3|set/times.mp3|set/08.mp3" -acodec copy 05_08.mp3
ffmpeg -i "concat:set/05.mp3|set/times.mp3|set/09.mp3" -acodec copy 05_09.mp3
ffmpeg -i "concat:set/06.mp3|set/times.mp3|set/06.mp3" -acodec copy 06_06.mp3
ffmpeg -i "concat:set/06.mp3|set/times.mp3|set/07.mp3" -acodec copy 06_07.mp3
ffmpeg -i "concat:set/06.mp3|set/times.mp3|set/08.mp3" -acodec copy 06_08.mp3
ffmpeg -i "concat:set/06.mp3|set/times.mp3|set/09.mp3" -acodec copy 06_09.mp3
ffmpeg -i "concat:set/07.mp3|set/times.mp3|set/07.mp3" -acodec copy 07_07.mp3
ffmpeg -i "concat:set/07.mp3|set/times.mp3|set/08.mp3" -acodec copy 07_08.mp3
ffmpeg -i "concat:set/07.mp3|set/times.mp3|set/09.mp3" -acodec copy 07_09.mp3
ffmpeg -i "concat:set/08.mp3|set/times.mp3|set/08.mp3" -acodec copy 08_08.mp3
ffmpeg -i "concat:set/08.mp3|set/times.mp3|set/09.mp3" -acodec copy 08_09.mp3
ffmpeg -i "concat:set/09.mp3|set/times.mp3|set/09.mp3" -acodec copy 09_09.mp3

ffmpeg -i 03_02.mp3 -acodec pcm_u8 -ar 22050 03_02.wav
ffmpeg -i 03_03.mp3 -acodec pcm_u8 -ar 22050 03_03.wav
ffmpeg -i 03_04.mp3 -acodec pcm_u8 -ar 22050 03_04.wav
ffmpeg -i 03_05.mp3 -acodec pcm_u8 -ar 22050 03_05.wav
ffmpeg -i 03_06.mp3 -acodec pcm_u8 -ar 22050 03_06.wav
ffmpeg -i 03_07.mp3 -acodec pcm_u8 -ar 22050 03_07.wav
ffmpeg -i 03_08.mp3 -acodec pcm_u8 -ar 22050 03_08.wav
ffmpeg -i 03_09.mp3 -acodec pcm_u8 -ar 22050 03_09.wav
ffmpeg -i 04_04.mp3 -acodec pcm_u8 -ar 22050 04_04.wav
ffmpeg -i 04_05.mp3 -acodec pcm_u8 -ar 22050 04_05.wav
ffmpeg -i 04_06.mp3 -acodec pcm_u8 -ar 22050 04_06.wav
ffmpeg -i 04_07.mp3 -acodec pcm_u8 -ar 22050 04_07.wav
ffmpeg -i 04_08.mp3 -acodec pcm_u8 -ar 22050 04_08.wav
ffmpeg -i 04_09.mp3 -acodec pcm_u8 -ar 22050 04_09.wav
ffmpeg -i 05_05.mp3 -acodec pcm_u8 -ar 22050 05_05.wav
ffmpeg -i 05_06.mp3 -acodec pcm_u8 -ar 22050 05_06.wav
ffmpeg -i 05_07.mp3 -acodec pcm_u8 -ar 22050 05_07.wav
ffmpeg -i 05_08.mp3 -acodec pcm_u8 -ar 22050 05_08.wav
ffmpeg -i 05_09.mp3 -acodec pcm_u8 -ar 22050 05_09.wav
ffmpeg -i 06_06.mp3 -acodec pcm_u8 -ar 22050 06_06.wav
ffmpeg -i 06_07.mp3 -acodec pcm_u8 -ar 22050 06_07.wav
ffmpeg -i 06_08.mp3 -acodec pcm_u8 -ar 22050 06_08.wav
ffmpeg -i 06_09.mp3 -acodec pcm_u8 -ar 22050 06_09.wav
ffmpeg -i 07_07.mp3 -acodec pcm_u8 -ar 22050 07_07.wav
ffmpeg -i 07_08.mp3 -acodec pcm_u8 -ar 22050 07_08.wav
ffmpeg -i 07_09.mp3 -acodec pcm_u8 -ar 22050 07_09.wav
ffmpeg -i 08_08.mp3 -acodec pcm_u8 -ar 22050 08_08.wav
ffmpeg -i 08_09.mp3 -acodec pcm_u8 -ar 22050 08_09.wav
ffmpeg -i 09_09.mp3 -acodec pcm_u8 -ar 22050 09_09.wav
