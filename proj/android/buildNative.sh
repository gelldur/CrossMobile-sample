#!/bin/bash
cd $(dirname $0)
./gradlew --console=plain :app:externalNativeBuildDebug --info
