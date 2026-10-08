# Installation and first launch

Before you start, check that your device meets the [requirements](../../README.md#device-requirements):
an Adreno 6xx/7xx GPU, Android 10+, about 15 GB free, and a controller.

You need two files from your own copy of the game:

| File | What it is |
|---|---|
| `something.iso` | The GTA IV Xbox 360 disc image (USA release, about 7.8 GB). |
| Title update 8 | Version 0.0.8.5 for the USA release, either the STFS package (a file with a long hexadecimal name) or a raw `default.xexp`. |

## 1. Install the APK

1. Download the latest `LibertyRecompAndroid-*.apk` from the [Releases](../../../../releases) page.
2. Open it on the device and allow installing from this source when Android asks.
3. The app appears as **Liberty Recompiled** (package `com.libertyrecomp`).

## 2. Launch once to create the app folder

Start the app once. It creates its data folder and shows the installer. Close the app for now.
The **Select File / Select Folder** buttons do not work on Android (see the note below).

The app keeps everything in its own external data folder, so it needs no storage permission:

```
Internal storage/Android/data/com.libertyrecomp/files/
├── install/          <- put the disc image and the title update here
├── LibertyRecomp/
│   ├── game/         the installed game (about 6.5 GB)
│   ├── saves/        your save games
│   └── shader_cache/
├── args.txt          settings, see ADVANCED.md
└── ...
```

## 3. Copy the game files into `install/`

Copy both files into `Android/data/com.libertyrecomp/files/install/`:

- the disc image, which must end in `.iso`;
- the title update file under any other name. If several non-`.iso` files are there, the largest one
  is used.

Ways to copy:

- **From a PC over USB (easiest).** Connect the device in file transfer (MTP) mode. Open
  `Internal storage > Android > data > com.libertyrecomp > files > install` and copy the two files in.
- **With adb:**
  ```
  adb push GTAIV.iso /sdcard/Android/data/com.libertyrecomp/files/install/game.iso
  adb push <title-update-file> /sdcard/Android/data/com.libertyrecomp/files/install/title_update
  ```
- **On the device.** Since Android 11, most file managers cannot write into `Android/data`. Some
  can with extra setup, for example through Shizuku. If yours cannot, use a PC.

## 4. Launch and install

Start the app again. It finds the files in `install/`, fills in **Base game** and
**Title update v8**, checks the disc and starts the installation by itself. Installation takes
several minutes. Leave the screen on and the app in the foreground until it finishes.

This is the installer as it looks before any source is selected:

![The Liberty Recompiled installer on Android](images/installer.png)

The game files are installed to the folder shown at the bottom
(`.../com.libertyrecomp/files/LibertyRecomp`). When the installation completes, the game starts.

> [!NOTE]
> **Why not the Select File buttons?** On Android, the system file picker returns `content://`
> links rather than file paths, and the installer cannot read those. The `install/` folder avoids
> the picker completely. You can also point the installer at files somewhere else on the device:
> add `--install_game_source=/full/path/to/game.iso` and `--install_update_source=/full/path/to/update`
> to `args.txt`. The app needs read access to that location, and `Android/data` of this app always
> works.

## 5. After the installation

- **Free the space.** Once the game runs, you can delete the two files in `install/`. That gives
  back about 7.8 GB, and they are not needed again.
- **The first minutes are slower.** Shaders are compiled the first time they are needed, so you
  will see some hitches. They are cached in `shader_cache/` and stay smooth on later runs.
- **Controls.** Use the device's built-in controls or a connected gamepad. The layout is the Xbox
  360 one.

## Upgrading to a newer version

Install the new APK over the old one. The game, saves and settings are kept.

`args.txt` is copied from the APK's defaults **only when it does not exist**. Your old `args.txt`
keeps overriding whatever the new version changed. To get the new defaults, delete
`Android/data/com.libertyrecomp/files/args.txt` before launching the new version. If you had
custom settings, apply them again afterwards.

If Android refuses to install over the old version (a signature mismatch between builds from
different machines), uninstall it first. **Back up `LibertyRecomp/saves/` before you do:**
uninstalling an app deletes its `Android/data` folder, which contains the installed game and your
saves.

## Troubleshooting

| Symptom | What to check |
|---|---|
| The app closes right after launch | Unsupported GPU (not an Adreno 6xx/7xx) or an ARMv8.0 CPU, see the [requirements](../../README.md#device-requirements). Also check for an invalid line in `args.txt`; deleting the file restores the defaults. |
| The installer shows **Not selected** | The files are not directly inside `files/install/`, or the disc image does not end in `.iso`. |
| The installer rejects the title update | It must be TU8 for the **USA** release (0.0.8.5). The PAL update (0.0.8.6) is not accepted. |
| Black screen or a crash after changing settings | Delete `args.txt` (defaults come back) and `live_cvars.txt` if you used it. |
| Something else | Collect a log as described in [ADVANCED.md](ADVANCED.md#logs). |
