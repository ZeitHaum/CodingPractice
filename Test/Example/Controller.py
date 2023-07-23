import multiprocessing as mp
import subprocess

#file_path in coderunner is current workspace.
socket_file_name = "conn.txt"

def start_server():
    subprocess.run(['.\\server.exe', '<', f'.\\{socket_file_name}'], shell=True)
    
def start_client():
    subprocess.run(['.\\client.exe', '>', f'.\\{socket_file_name}'], shell=True)
    
if __name__ == "__main__":
    start_client()
    start_server()