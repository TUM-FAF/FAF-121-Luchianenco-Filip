# Laboratory Work No. 1

## Command Line Interface; CLI Editors; Setting Server Environment; Version Control Systems

### Mandatory Tasks:
  - Connect to a remote server via SSH
  - Initialize a repository on server
  - Create a file in repository folder, write in your name, save it and commit it

### Tasks With Points:
  - Connect to server using public key (1 pt)
  - Create 2 more branches with at least one unique committed file per branch (1 pt)
  - Set a branch to track a remote origin on which you are able to push (ex. github, bitbucket or a custom server) (1 pt)
  - Reset a branch to previous commit, reset a branch to some specific commit (1 pt)
  - Restore a reset branch back to its previous state (1 pt)
  - GIT cherry-pick, rebase (1 pt)
  - Create a VCS hook (1 pt)
  - Install a code-highlighter plugin in your CLI text editor (1 pt)
  - Create a VCS alias (1 pt)
  - Master any CLI editor (ex. VIM). Learn 10 commands to prove your mastery (1 pt)
  - Create your own server (ex. virtual machine) (2 pt)
  - Create a VCS merge conflict and solve it (1 pt)

## Report

### Connect to a remote server via SSH

  I have connected to fafstudent@95.65.10.71 to ssh server *using the provided password from Facebook* by typing the following command in Terminal:
  
  `ssh fafstudent@95.65.10.**`  
  
### Initialize a repository on server & Create a file in repository folder, write in your name, save it and commit it

  The repository has been initiated as follows:

```sh
  ssh fafstudent@95.65.10.**
  mkdir Luchianenco_Filip_FAF-121
  cd Luchianenco_Filip_FAF-121/
  echo "LuchFilip added some text to README.md  from Terminal" >> README.md
  mkdir IDE
  cd IDE/
  vim LuchFilip.txt
  #pressed i to enter insert mode and wrote some text*
  #pressed ESC and typed
  wq #write & quit
  cd ../.. 
  git init
  git status
  git add #add necessary files to git
  git commit -m 'initial commit'
```

### Connect to server using public key

  In order to use a public key we need to created the key on local machine, insert the content of the public key `.pub` to authorized_keys file which is located in `.ssh/` folder. Then `chmod 600` all keys on local and remote machine, so that other users cannot access them. Here are the commands:
  
```sh

  cd .ssh/
  ssh-keygen # name of file: luchfilip; also password may be written
  # two files are created luchfilip and luchfilip.pub 
  cat luchfilip.pub | copy #copy will copy the output to clipboard
  chmod 600 luchfilip* # chmod both files
  ssh fafstudent@95.65.10.**
  cd .ssh/
  echo "<paste key here>" >> authorized_keys
  chmod 600 authorized_keys
  exit #close session
  #test if everything works fine
  ssh fafstudent@95.65.10.**
  #I am asked to write the password which I wrote when the key was created 
  
```
  
### Create 2 more branches with at least one unique committed file per branch

```ssh
  
  #on remote machone
  git branch develop
  #push branch on github if necessary
  git push origin develop
  #switch to new branch
  git checkout develop
  #make sure we are in the new branch
  git branch
    #output
  *develop
   master
  echo "content of the new created file in the new branch" >> luchfilip_develop.txt
  git add luchfilip_develop.txt
  git commit -m 'new branch created'
  git branch release
```

### Set a branch to track a remote origin on which you are able to push

```sh
  #on remote machine
  git branch --track newFeature origin/master
  #output
  Branch newFeature set up to track local branch master.
  #check result
  git branch -a
  develop
* master
  newFeature
  release

```
  
### Reset a branch to previous commit, reset a branch to some specific commit

  Reset to previews commit
  `git reset --soft 'HEAD' `
  
  Reset to some specific commit
  `git log` *output commit log to see which one we want to reset and copy the first ~6 characters*
  `git reset --hard f014ed`
  
### 

```sh
  git fsck --lost-found
  git reflog
  
```
  
