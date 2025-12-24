# Mothership

> If you just want to **get started on using the tool**, just skip to -- !

## How it started

As a CS student, i'm currently following the path to become a full-stack web dev. However, as someone passioned about CS, it's just not enough for me, and i'm always hungry for more, especially outside of the world wide web. I already know Java (one of my favourite languages), C and Python, and since the JVM is built using C++, learning this language is the next logical step.

When starting out C++, i discovered CMake. For a long while, i found it heinous, as i felt like i had to learn a config language just to learn a new language. I didn't want to just generate it blindly by AI, so i delved into the basics.
In another project (written in Java) i needed Maven in order to enable annotation processing, and i litteraly never got the setup right, because i didn't get Maven.

These experiences frustrated me a lot, because CMake, Maven/Gradle sure are extremely powerful tools, and technically you don't need *too much* knowledge to get a project working, but still, what if it was **simpler** ?

## The vision

With this tool, one may start coding in C++ without ever needing to either type long g++ commands listing all files and headers or to type a CMAKE config file. You type a few line of configs (specifying a project name, a version and an environment), you run in your terminal

```bash
mothership run
```

and you're done !

This tool also allows you to

- Run Java code without having to rely on the IDE

- Not type `python -m venv [project-name]` to initialize a python virtual env and forgetting to `source bin/activate` it when trying to run it

## Get started

1. Create a folder for your project and cd into it
2. type this command :

```bash
mothership init <project-name> <environment>
```

> This will create a basic `spaceship.toml` file in the current directory

3. Use `mothership build` to build your project (except when in Python) or `mothership run` to run it

And you are done !

## Hooks

You can add hooks that will execute when you use `mothership build` or run ! Hooks are can either be scripts, commands, executables - anything that runs basically !

### Config syntax

```toml
project_name="my-cool-project"
environment="cpp"
version=0

[build_opts.hooks.linting]
command="clang-tidy @parameter-file"
when="before"

[run_opts.hooks.launch_my_server]
path="./server_run.bash"
when="before"
```

Now whenever you type `mothership build`, the "linting"'s clang-tidy command will be launched. Same goes for the ./server_run.bash script, that will be launched right before g++ (launched by `mothership run` will be launched.).
