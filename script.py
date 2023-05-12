import os
import shutil
import subprocess

# Replace these with your own values
new_repo_url = "https://github.com/Prithvi-k/IntroToSoftwareSystems"
repos_to_move = ["https://github.com/CS6-201-ISS-S23/tutorial-1-Prithvi-k",
                 "https://github.com/CS6-201-ISS-S23/tutorial-2-Prithvi-k",
                 "https://github.com/CS6-201-ISS-S23/tutorial-3-Prithvi-k",
                 "https://github.com/CS6-201-ISS-S23/tutorial-4-Prithvi-k",
                 "https://github.com/CS6-201-ISS-S23/tutorial-5-sql-Prithvi-k",
                 "https://github.com/CS6-201-ISS-S23/assignment-1-Prithvi-k",
                 "https://github.com/CS6-201-ISS-S23/assignment-2-Prithvi-k",
                 "https://github.com/CS6-201-ISS-S23/project-cup-noodles"]

# Clone each repo and move its contents to a new folder in the new repo
# for repo_url in repos_to_move:
#     # Clone the repo
#     repo_name = os.path.splitext(os.path.basename(repo_url))[0].split("/")[-1]
#     print("here: " + repo_name)
#     subprocess.run(["git", "clone", repo_url])

# def remove_git_repos(folder_path):
#     for dir_name in os.listdir(folder_path):
#         dir_path = os.path.join(folder_path, dir_name)
#         if os.path.isdir(dir_path):
#             git_path = os.path.join(dir_path, ".git")
#             if os.path.exists(git_path):
#                 shutil.rmtree(git_path)
#                 print(f"Git repository removed from {dir_path}.")

# # Example usage
# remove_git_repos("/home/prithvi-karthik/Documents/IntroToSoftwareSystems/")

# Initialize and push the new repo
# os.chdir("IntroToSoftwareSystems/")
subprocess.run(["git", "init"])
subprocess.run(["git", "remote", "add", "origin", new_repo_url])
subprocess.run(["git", "add", "."])
subprocess.run(["git", "commit", "-m", "Move contents to new repository"])
subprocess.run(["git", "push", "-u", "origin", "master"])
