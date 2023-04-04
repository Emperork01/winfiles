import paramiko
import os
import sys
import subprocess

# implement pip as a subprocess:
subprocess.check_call([sys.executable, '-m', 'pip', 'install',
'paramiko'])

local_path = "C:\\Users\\KaranHemnani\\Downloads\\SanerNow_OnlyPM_5.3"
remote_path = "/home/sp-agent/Downloads/SanerNow_Agent/"
#will throw error if the path already has the file  

hostname = "192.168.2.60"
username = "sp-agent"
password = "2386"

# Create an SSH client object
ssh = paramiko.SSHClient()

# Automatically add the remote host's SSH key to the local key store
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())

# Connect to the remote system using SSH
ssh.connect(hostname=hostname, username=username, password=password)

# Create an SFTP client object using the SSH connection
sftp = ssh.open_sftp()

# Create a new remote directory
sftp.mkdir(remote_path)

# Transfer files to the remote directory
for root, dirs, files in os.walk(local_path):
    for file in files:
        local_file_path = os.path.join(root, file)
        remote_file_path = os.path.join(remote_path, os.path.relpath(local_file_path, local_path))
        sftp.put(local_file_path, remote_file_path)
        print (remote_file_path)

# Close the SFTP and SSH connections
sftp.close()
ssh.close()
