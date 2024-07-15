
rpm_version=`git describe --tags --abbrev=0 | sed "s/^v//g"`
#release=`git describe --tags | cut -d- -f2 | tr - _`
rpm_version=1.0.79
rpm_release=0
topdir=$(pwd)
for spec in tgtd.spec.in ; do
	cat $spec |
	sed "s/@PROJECT_VERSION@/$rpm_version/g" |
	sed "s/@RPM_RELEASE@/$rpm_release/g" |
	sed "s#@TGTD_SOURCE@#$topdir#g"  > `echo $spec | sed 's/.in$//'`
    done
