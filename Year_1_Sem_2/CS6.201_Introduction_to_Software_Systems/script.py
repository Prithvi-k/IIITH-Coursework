import os
import shutil
import subprocess

# Variables
github_username = input("Enter your github username: ")
project_repo_name = input("Enter the name of the project repo: ")
path_to_save = os.curdir

new_repo_url = f"https://github.com/{github_username}/IntroToSoftwareSystems"
repos_to_move = [f"https://github.com/CS6-201-ISS-S23/tutorial-1-{github_username}",
                 f"https://github.com/CS6-201-ISS-S23/tutorial-2-{github_username}",
                 f"https://github.com/CS6-201-ISS-S23/tutorial-3-{github_username}",
                 f"https://github.com/CS6-201-ISS-S23/tutorial-4-{github_username}",
                 f"https://github.com/CS6-201-ISS-S23/tutorial-5-sql-{github_username}",
                 f"https://github.com/CS6-201-ISS-S23/assignment-1-{github_username}",
                 f"https://github.com/CS6-201-ISS-S23/assignment-2-{github_username}",
                 f"https://github.com/CS6-201-ISS-S23/{project_repo_name}"]

# Clone each repo and move its contents to a new folder in the new repo
for repo_url in repos_to_move:
    # Clone the repo
    repo_name = os.path.splitext(os.path.basename(repo_url))[0].split("/")[-1]
    subprocess.run(["git", "clone", repo_url])

def remove_git_repos(folder_path):
    for dir_name in os.listdir(folder_path):
        dir_path = os.path.join(folder_path, dir_name)
        if os.path.isdir(dir_path):
            git_path = os.path.join(dir_path, ".git")
            if os.path.exists(git_path):
                shutil.rmtree(git_path)
                print(f"Git repository removed from {dir_path}.")

remove_git_repos(f"{path_to_save}")

# Initialize and push the new repo
subprocess.run(["git", "init"])
subprocess.run(["git", "remote", "add", "origin", new_repo_url])
subprocess.run(["git", "add", "."])
subprocess.run(["git", "commit", "-m", "Move contents to new repository"])
subprocess.run(["git", "push", "-u", "origin", "master"])
