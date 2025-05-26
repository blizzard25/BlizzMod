PLACEHOLDER README:

BlizzMod is a modloader meant to expose relevant IL2CPP functions in Marvel Contest of Champions. In its current state it works, but all functions are located in InitHooks.cpp. A todo item is separating them into cleaner classes and exposing them in API form for actual mods to be written.

I have not included a precompiled binary in the releases yet becauses there are no mods. In order to create a mod, you will need to edit the project directly. You can do that by cloning the repository and editing the functions located in InitHooks.cpp. Soon this repository will be a modloader only and will not need to be edited and I will generate precompiled binaries.

Please check back for the installer project if you are having trouble with Easy Anti Cheat. The patch will be included in the installer, and I don't want to include the patch here. If you are testing the modloader before it's made, send me a message and I'll be happy to tell you how to fix it. It's simple and takes about 5 seconds to do, anyone with half a brain can work around it.

Once you have compiled the project, check the launcher project for how to inject: https://github.com/blizzard25/BlizzModLauncher
