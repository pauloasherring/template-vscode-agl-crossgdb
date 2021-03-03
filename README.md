# template-vscode-agl-crossgdb

A CMake Template Project for VSCode enabling remote debugging.

This template project implements the required things for a complete development arch based on Automotive Grade Linux. Required tools:

* Microsoft Visual Studio Code (VSCode);
* VSCode's extensions pack for C/C++: C/C++ Extension Pack (ms-vscode.cpptools-extension-pack);
* Automotive Grade Linux SDK installed to the default path (/opt/agl-sdk/**);
* A target flashed with an AGL image, enabled with debugging tools;
* sshpass, for sending inline ssh password (sudo apt install sshpass ).

# Usage

Run VSCode from `configAndCode.sh, configure your target on settings.json, build with CTRL + SHIFT + B - CMake Build -, and deploy and debug with F5.

For a more detailed view, read below.

## Starting up

You are required to first source AGL's SDK config file, otherwise, CMake won't be able to correctly identify you development environment and tooling.

To do it, run `configAndCode.sh , this shell script will source AGL's SDK config file and then open VSCode on the current folder.

If are feeling wild, you can also do it by hand:

```
. /opt/agl-sdk/*/environment-setup-aarch64-agl-linux 
code .
```

## Configuring

Configuration is done on `settings.json. There, you are required to input the following:

* Your target's IP (targetIP);
* Your target's UserName (targetUser);
* Your target's Username's password (targetPassword);
* Your target's destination folder, for remote deployment (targetDestFolder);
* Your binary's file name (targetAppName);
* Your binary's path (targetInFolder);

## Building

There are three tasks configured, accessible through CTRL + SHIFT + B:

* CMake Build: runs cmake configure, build and the run the build system;
* CMake Clean: deletes all built files, but keeps caches and others;
* Delete build folder: permanently deletes the build folder, for a harsher reset.

## Deploying and debugging

There is a single debug target, accessible through F5. When you hit F5, it starts a local shell and performs the following tasks:

* Copy target binary to the target (scp);
* Make the binary executabled on target (chmod +x);
* Terminate all and any running gdbserver instances;
* Starts a new gdbserver instance on port 3000, with the target binary as child process;
* Prints a "Program terminated on target..." on completion.

After the gdbserver has been started, your VSCode's local gdb will connect to the remote instance and stop on the main function.

# Caveats and known issues

* Currenytly not tested with users other than root.

