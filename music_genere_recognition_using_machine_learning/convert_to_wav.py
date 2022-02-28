from pydub import AudioSegment
import config
import os
import shutil
#------------------------------#
AudioSegment.converter="C:\\FFmpeg\\bin\\ffmpeg"
#------------------------------#

print("Creating the testFiles_wav folder)
os.mkdir(config.Test.TEST_DATA_PATH)

#extracting the name of the files
name_of_files=os.listdir(config.Test.TEST_DATA_PATH_RAW)

#moving in the array name_of_files
for x in name_of_files:
    filename, fileextension = os.path.splitext(x)
    if fileextension==".wav":
        src=config.Test.TEST_DATA_PATH_RAW+"\\"+x
        dst=config.Test.TEST_DATA_PATH+"\\"+x
        shutil.copy(src,dst)
    elif fileextension==".mp3":
        print("mp3 found")
        src=config.Test.TEST_DATA_PATH_RAW+"\\"+x
        filename, fileextension = os.path.splitext(x)
        dst=config.Test.TEST_DATA_PATH+"\\"+filename+".wav"
        sound=AudioSegment.from_mp3(src)
        
        halfway_point=len(sound)/2
        second_half = sound[halfway_point:]
        second_half.export(dst,format="wav")

