tga-wic-codec
=============

Targa WIC codec

Based on dds-wic-codec at googlecode: http://code.google.com/p/dds-wic-codec

Installation
==============

Check-out source, build and execute `regsvr32 tga-wic-codec.dll` command (_administrator rights_ are required to register the codec properly).

`tga-wic-codec.dll` should be signed with trusted certificate. You can easily make your own certificate, sign the dll and put the certificate to Windows trusted root certificates store **TODO**.
* http://stackoverflow.com/questions/84847/how-do-i-create-a-self-signed-certificate-for-code-signing-on-windows

In Windows Vista and Windows 7 you can use this codec to show thumbnails of files in supported formats in Windows Explorer.

**TODO** To enable thumbnails you need the following registry entries (here for PVR):

```
[HKEY_CLASSES_ROOT.pvr\ShellEx]
[HKEY_CLASSES_ROOT.pvr\ShellEx{e357fccd-a995-4576-b01f-234630154e96}] @="{C7657C4A-9F68-40fa-A4DF-96BC08EB3551}"
```
