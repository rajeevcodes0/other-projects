import os
import shutil
#---------------------#
def createFolders(result_array):
    playlist_location="C:\\Users\\Dell\\Desktop\\playlist"
    os.mkdir(playlist_location)
    result_array_distinct=list(set(result_array))
    
    for x in result_array_distinct:
        os.mkdir(playlist_location+"\\"+x)

def moveSongs(result_array):
    path_of_testFiles="C:\\Users\\Dell\\Desktop\\testFiles"
    playlist_location="C:\\Users\\Dell\\Desktop\\playlist"
    name_of_files=os.listdir(path_of_testFiles)
    
    index=0
    for x in name_of_files:
        src=path_of_testFiles+"\\"+x
        dst=playlist_location+"\\"+result_array[index]
        print(src,dst)
        index=index+1
        shutil.copy(src,dst)
        
    