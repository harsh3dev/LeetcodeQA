import os

# Path to the directory where your solution folders are stored
solutions_dir = "/home/runner/work/LeetcodeQA/LeetcodeQA/"  # e.g., "leetcode-solutions"

# Path to the README file
readme_path = "README.md"

# Get a list of all folders in the solutions directory
solution_folders = [
    f for f in os.listdir(solutions_dir) if os.path.isdir(os.path.join(solutions_dir, f))
]

# Count the total number of solved problems
total_solved = len(solution_folders)

# Extract problem numbers and names from folder names
problem_list = sorted(solution_folders, key=lambda x: int(x.split('-')[0]))

# Prepare the summary content
summary_content = f"### LeetCode Solutions Summary\n\n"
summary_content += f"**Total Problems Solved:** {total_solved}\n\n"
summary_content += f"**List of Problems Solved:**\n\n"

for problem in problem_list:
    summary_content += f"- {problem}\n"

# Read the existing README content
with open(readme_path, "r") as file:
    readme_content = file.readlines()

# Markers for the section of the README to be updated
start_marker = "<!-- SOLVED_PROBLEMS_START -->\n"
end_marker = "<!-- SOLVED_PROBLEMS_END -->\n"

# Find the indexes for the markers in the README file
try:
    start_index = readme_content.index(start_marker) + 1
    end_index = readme_content.index(end_marker)
except ValueError:
    # If markers are not found, set defaults (to append at the end)
    start_index = len(readme_content)
    readme_content.append("\n" + start_marker)
    readme_content.append(end_marker + "\n")
    end_index = len(readme_content) - 1

# Insert the updated content between the markers
readme_content[start_index:end_index] = summary_content.splitlines(keepends=True)

# Write the updated content back to the README file
with open(readme_path, "w") as file:
    file.writelines(readme_content)
