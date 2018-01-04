import os
import urllib.request
import zipfile

def downloadZip(url, extractedFolderName = None):
    zipFileName = url.rsplit('/', 1)[-1]
    assert zipFileName.endswith('.zip')
    if not extractedFolderName:
        extractedFolderName = zipFileName[:-4]
    if not os.path.exists(extractedFolderName):
        print('Downloading %s' % zipFileName)
        urllib.request.urlretrieve(url, zipFileName)
        zipfile.ZipFile(zipFileName).extractall()
        os.remove(zipFileName)
        assert os.path.exists(extractedFolderName)

externFolder = os.path.normpath(os.path.join(__file__, '../extern'))
os.makedirs(externFolder, exist_ok=True)
os.chdir(externFolder)

# Cairo
downloadZip('https://github.com/preshing/cairo-windows/releases/download/1.15.10/cairo-windows-1.15.10.zip', 'cairo-windows-1.15.10')
