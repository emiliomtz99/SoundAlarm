from cx_Freeze import setup,Executable
import cx_Freeze

includefiles = ['Alarm.mp3', 'haboots-86f0b-firebase-adminsdk-kxjz1-771d99108a.json']
includes = []
excludes = []
packages = []

exe = [cx_Freeze.Executable("alarma.py", base = "Win32GUI")] # <-- HERE

setup(
    name = 'myapp',
    version = '0.1',
    description = 'ALARM ULTRASONIC BLAST',
    author = 'HABOOTS',
    author_email = '',
    options = {'build_exe': {'includes':includes,'excludes':excludes,'packages':packages,'include_files':includefiles}}, 
    executables = exe
)