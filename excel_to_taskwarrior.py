import os
import re
import pandas as pd


print(pd.read_excel("/home/hari/Documents/reset_sprint.ods"))

task_dict = {
        "desc": "dummy",
        "annotation": ["annotation 1", "annotation 2", "annotation 3"],
        "project": "",
        "timeframe": "near future",
        "effort": "blitzkreig",
        "type": "execution",
        }

        
response = os.popen(f"task add \"{task_dict['desc']}\"").read()
match = re.match(r"Created task (\d+).", response)
if match:
    task_id = match.group(1)
    print(task_id)

