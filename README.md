# Mothership
> aka `mt`, `mts`, `ms`

## The goal

Mothership aims to be an **excruciatingly simple package manager**. Its goal is to avoid to **beginners** having to learn everything
about CMake when they just want to try out C++, or about Maven/Gradle and folder structure when trying a simple Java program.

It also applies to devs when they want to **prototype**, test or "see something" about a language without relying on an IDE 
to auto-gen a project structure.

It will **abstract away build and run steps** from both **C++**, **Java** into just one command and a config file, the command being :

`mothership build`

and the config file (called spaceship.toml, one by projects) maybe looking like

```toml
project_name="my-java-project"
environment="java"
version=0

[build_opts]
build_dir="mt-build"
build_path="."
```

Mothership will also allow you to specify hook scripts that will automatically run  when calling 
`mothership run` or `mothership build`, before or after the actual building or running.

## languages that will be supported
- Java
- C++
- Python

## Future features
- Adding docker support, so you can run your project into an auto made docker container
- Adding a `graal` option to `mothership run` | `build` when used on a Java project, so you can have a **native image** 
executable instead of the traditionnal runtime
