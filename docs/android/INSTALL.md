# Installation and first launch

Before you start, check that your device meets the [requirements](../../README.md#device-requirements):
an Adreno 6xx/7xx GPU, Android 10+, about 15 GB free, and a controller.

You need two files from your own copy of the game:

| File | What it is |
|---|---|
| `something.iso` | The GTA IV Xbox 360 disc image (USA release, about 7.8 GB). |
| Title update 8 | Version 0.0.8.5 for the USA release, either the STFS package (a file with a long hexadecimal name) or a raw `default.xexp`. |

The MD5 and SHA-1 hashes of the tested files are listed in the
[README](../../README.md#game-files-required).

## 1. Install the APK

1. Download the latest `LibertyRecompAndroid-*.apk` from the [Releases](../../../../releases) page.
2. Open it on the device and allow installing from this source when Android asks.
3. The app appears as **Liberty Recompiled** (package `com.libertyrecomp`).

## 2. Launch once to create the app folder

Start the app once. It creates its data folder. On 0.5.6.3 and newer it opens on the
[launcher](#the-launcher-0563-and-newer), which shows where the files go. Older versions go
straight to the installer. Close the app for now. The installer's **Select File / Select Folder**
buttons do not work on Android (see the note below).

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

Start the app again, and press **Play** on the launcher (0.5.6.3 and newer). It finds the files
in `install/`, fills in **Base game** and **Title update v8**, checks the disc and starts the
installation by itself. Installation takes
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

## The launcher (0.5.6.3 and newer)

![The launcher](images/launcher.png)

The app always opens on this screen:

- **Status.** Whether the game is installed. If it is not, the screen says whether the disc image
  and the title update were found in `install/`. If the last start failed, the reason is shown.
- **Play** starts the game (the **Start** button on a gamepad does the same). It always starts a
  fresh game process with the driver selected on the right, so a driver change always applies.
  If you leave the game with the Home button, the app icon takes you back to the running game,
  not to the launcher.
- **Vulkan driver.** Choose the bundled Turnip (default), the device's own driver, or a driver you
  imported. **Import driver (.zip)** opens the system file picker. Pick an AdrenoTools/Turnip
  driver zip (a `.so` and usually a `meta.json`), and it is unpacked, added to the list and
  selected. **Remove** deletes an imported driver. The choice is saved in `driver.txt` (see
  [ADVANCED.md](ADVANCED.md#driver-selection-drivertxt)).

Gamepad: the D-pad moves between the controls, **A** selects, **B** closes the app and **Start**
plays.

## 5. After the installation

- **Free the space.** Once the game runs, you can delete the two files in `install/`. That gives
  back about 7.8 GB, and they are not needed again.
- **The first minutes are slower.** Shaders are compiled the first time they are needed, so you
  will see some hitches. They are cached in `shader_cache/` and stay smooth on later runs.
- **Controls.** An XInput (Xbox-layout) gamepad is strongly recommended: the built-in controls
  of a handheld, or an Xbox controller over Bluetooth or USB. The on-screen touch controls appear
  only when no controller is connected, and they are untested on Android (see
  [Controls](../../README.md#controls)).

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
| A dialog says no usable Vulkan driver / Vulkan 1.2 is needed | The GPU is not supported, see the [requirements](../../README.md#device-requirements). If you created `driver.txt`, delete it. Details are in `files/last_launch.txt`. |
| The app closes right after launch, without a dialog | An ARMv8.0 CPU (see the [requirements](../../README.md#device-requirements)) or an invalid line in `args.txt`. Deleting `args.txt` restores the defaults. Check `files/last_launch.txt`. |
| The installer shows **Not selected** | The files are not directly inside `files/install/`, or the disc image does not end in `.iso`. |
| The installer rejects the title update | It must be TU8 for the **USA** release (0.0.8.5). The PAL update (0.0.8.6) is not accepted. |
| Black screen or a crash after changing settings | Delete `args.txt` (defaults come back) and `live_cvars.txt` if you used it. |
| Something else | Collect a log as described in [ADVANCED.md](ADVANCED.md#logs) and open an issue on the [Issues](https://github.com/vaduur/LibertyRecompAndroid/issues) page. |

Questions, bugs and feedback all go to [Issues](https://github.com/vaduur/LibertyRecompAndroid/issues). Mention your device, the Android version and the port version.

### Collecting information without a PC

- **`files/last_launch.txt`** is written at every start. It holds the device, the chip, the GPU,
  the Android version and which Vulkan driver was used, or why none could be. Attach it to your
  issue.
- **The newest file in `files/Liberty Recompiled/logs/`** is the game's own log.
- **A full system log** (the same thing `adb logcat` gives) without a PC: enable Developer options
  (tap *Build number* seven times in *About phone*), then choose *Developer options > Take bug
  report*. Share the resulting zip.
- **The GPU and its Vulkan version:** the free *Vulkan Caps Viewer* or *AIDA64* apps show them.
