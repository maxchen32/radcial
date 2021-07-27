import time
import os
os.system("git add --all")
os.system("git commit -m updated"+time.strftime("%H:%M:%S"))
os.system("git push origin develop")