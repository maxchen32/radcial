import time
import os

os.system("git add *")
os.system("git commit -m updated"+time.strftime("%H:%M:%S"))
os.system("git push origin master")
