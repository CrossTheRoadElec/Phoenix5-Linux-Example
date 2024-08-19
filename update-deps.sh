echo "Usage: ./update-deps <v5_version> <v6_version>"

wget https://maven.ctr-electronics.com/release/com/ctre/phoenix/api-cpp/$1/api-cpp-$1-headers.zip
wget https://maven.ctr-electronics.com/release/com/ctre/phoenix/api-cpp/$1/api-cpp-$1-linuxarm64.zip
wget https://maven.ctr-electronics.com/release/com/ctre/phoenix/api-cpp/$1/api-cpp-$1-linuxarm32.zip
wget https://maven.ctr-electronics.com/release/com/ctre/phoenix/api-cpp/$1/api-cpp-$1-linuxx86-64.zip

wget https://maven.ctr-electronics.com/release/com/ctre/phoenix/cci/$1/cci-$1-headers.zip
wget https://maven.ctr-electronics.com/release/com/ctre/phoenix/cci/$1/cci-$1-linuxarm64.zip
wget https://maven.ctr-electronics.com/release/com/ctre/phoenix/cci/$1/cci-$1-linuxarm32.zip
wget https://maven.ctr-electronics.com/release/com/ctre/phoenix/cci/$1/cci-$1-linuxx86-64.zip

wget https://maven.ctr-electronics.com/release/com/ctre/phoenix6/tools/$2/tools-$2-headers.zip
wget https://maven.ctr-electronics.com/release/com/ctre/phoenix6/tools/$2/tools-$2-linuxarm64.zip
wget https://maven.ctr-electronics.com/release/com/ctre/phoenix6/tools/$2/tools-$2-linuxarm32.zip
wget https://maven.ctr-electronics.com/release/com/ctre/phoenix6/tools/$2/tools-$2-linuxx86-64.zip

rm -rf include
mkdir include
unzip -o api-cpp-$1-headers.zip -d include
unzip -o cci-$1-headers.zip -d include
unzip -o tools-$2-headers.zip -d include

mkdir tmp
rm -rf lib
mkdir lib
mkdir lib/arm64
unzip -o api-cpp-$1-linuxarm64.zip -d tmp
unzip -o cci-$1-linuxarm64.zip -d tmp
unzip -o tools-$2-linuxarm64.zip -d tmp 
mkdir lib/arm32
unzip -o api-cpp-$1-linuxarm32.zip -d tmp
unzip -o cci-$1-linuxarm32.zip -d tmp
unzip -o tools-$2-linuxarm32.zip -d tmp
mkdir lib/x86-64
unzip -o api-cpp-$1-linuxx86-64.zip -d tmp
unzip -o cci-$1-linuxx86-64.zip -d tmp
unzip -o tools-$2-linuxx86-64.zip -d tmp

mv tmp/linux/arm64/shared/* lib/arm64
mv tmp/linux/arm32/shared/* lib/arm32
mv tmp/linux/x86-64/shared/* lib/x86-64
rm -rf tmp

rm *.zip
