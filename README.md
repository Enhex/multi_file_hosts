# multi_file_hosts
Tool for creating hosts file from several files.

Currently only supporting Windows.

# Usage
Create a `files` directory next to the executable, and inside it place the text files that'll be concatenated into the hosts file.
If your current hosts file contains configurations, make sure to copy it into `files` first.

Run the `multi_files_hosts` executable, which will overwrite the operating system's hosts file with the content of all the files inside `files`.
