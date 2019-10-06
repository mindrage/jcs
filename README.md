<center>JCS - Jit Component System</center>
===
*JCS is very early in its development and what information that is displayed is planned design and features.*


## What is JCS?

JCS is a library that works on the principle to generate bytecode that will be executed in an isolated environment.

The components are structs that are dynamically defined and replaceable by interleaving / removing the new data when new changes come in.

By generating bytecode on the fly and translating to other platforms, high performance can be gained since it can be optimized for multiple platforms, even move certain calculations to the gpu by SPIR-V bytecode.

Since its an isolated environment, snapshots of the state can be stored pretty quickly and loaded in pretty fast as well.

Also parallellism will also be a high focus of the systems.

Design choises are inspired by EnTT and Specs (rust)

## Purpose

Main idea of JCS is to create an fast prototyping experience for a game engine, but also a way to create a library that can interface with scripting languages through FFI to gain pretty great performance.

## API

The Api is designed to be easily adaptable by other languages, so it will mostly only interface with enums, strings and numbers, Objects are reffered with a integer handle.

### Creating components

A component consists only of a list of members of a fixed types.
These components needs to be named and attributes needs to be listed with an index as well.

```cpp
    jcs_id transform = jcs_component_create("transform");
    jcs_attribute_set(transform, 0, "position", JCS_F32, 3, 1);
    jcs_attribute_set(transform, 1, "scale", JCS_F32, 3, 1);
    jcs_attribute_set(transform, 2, "rotation", JCS_F32, 4, 1);
```

Globally shared data between components are called uniforms.

```cpp
    jcs_id mesh = jcs_uniform_create("mesh");
    // Sub-components to create more elaborate structures
    jcs_attribute_set(mesh, 0, "transform", transform, 1, 1024);
    // You may also assign a max size to a uniform array.´
```


