NULL =
BUILT_SOURCES =
CLEANFILES = kod-output-blank kod-output-single kod-output-multiple debug-output-lfp-dec debug-output-lfp-bin debug-output-pkt
DISTCLEANFILES = kod-output-blank kod-output-single kod-output-multiple
EXTRA_PROGRAMS =

std_unity_list =					\
	$(srcdir)/../unity/auto/generate_test_runner.rb	\
	$(NULL)

run_unity =	cd $(srcdir) && ruby ../unity/auto/generate_test_runner.rb

# Use EXTRA_PROGRAMS for test files that are under development but
# not production-ready
#EXTRA_PROGRAMS +=		test-packetHandling test-packetProcessing

check_PROGRAMS =			\
	test-crypto			\
	test-keyFile			\
	test-kodDatabase		\
	test-kodFile			\
	test-networking			\
	test-packetHandling		\
	test-packetProcessing		\
	test-utilities			\
	$(NULL)

EXTRA_PROGRAMS += tests

tests_SOURCES =			\
	../tests_main.cpp	\
	g_crypto.cpp		\
	g_fileHandlingTest.h	\
	g_networking.cpp	\
	g_packetHandling.cpp	\
	g_packetProcessing.cpp	\
	g_sntptest.h		\
	$(NULL)

tests_LDADD =			\
	$(base_LDADD)		\
	$(GTEST_LDFLAGS)	\
	$(GTEST_LIBS)		\
	$(NULL)

tests_CPPFLAGS =		\
	$(AM_CPPFLAGS)		\
	$(CPPFLAGS)		\
	$(GTEST_CPPFLAGS)	\
	$(NULL)

AM_CXXFLAGS = $(GTEST_CXXFLAGS)

noinst_HEADERS =		\
	sntptest.h		\
	$(NULL)

dist_check_SCRIPTS =	tests-runner

EXTRA_DIST =				\
	data/debug-input-lfp-bin	\
	data/debug-input-lfp-dec	\
	data/debug-input-pkt		\
	data/key-test-ascii		\
	data/key-test-comments		\
	data/key-test-empty		\
	data/key-test-hex		\
	data/key-test-invalid-hex	\
	data/kod-expected-multiple	\
	data/kod-expected-single	\
	data/kod-test-blanks		\
	data/kod-test-correct		\
	data/kod-test-empty		\
	$(NULL)

CLEANFILES +=				\
	data/kod-output-multiple	\
	data/kod-output-single		\
	data/debug-output-pkt		\
	data/debug-output-lfp-dec	\
	data/kod-output-blank		\
	data/debug-output-lfp-bin	\
	$(NULL)

#split into LDADD and tests_LDADD?
base_LDADD =					\
	../libsntp.a				\
	$(LIBOPTS_LDADD)			\
	$(LDADD_LIBEVENT)			\
	$(top_builddir)/../libntp/libntp.a	\
	$(LDADD_LIBNTP)				\
	$(LDADD_NTP)				\
	$(NULL)

LDADD =						\
	$(base_LDADD)				\
	$(top_builddir)/unity/libunity.a	\
	$(LIBM)					\
	$(NULL)

AM_CFLAGS  = $(CFLAGS_NTP)

AM_CPPFLAGS  = $(SNTP_INCS)
AM_CPPFLAGS += -I$(srcdir)/..
AM_CPPFLAGS += -I$(top_srcdir)/../tests
AM_CPPFLAGS += $(LIBOPTS_CFLAGS)
AM_CPPFLAGS += $(CPPFLAGS_LIBEVENT)
AM_CPPFLAGS += $(CPPFLAGS_NTP)
AM_CPPFLAGS += -DUNITY_INCLUDE_CONFIG_H
#AM_CPPFLAGS += -I$(top_srcdir)/sntp/unity
AM_CPPFLAGS += -I$(top_srcdir)/unity

AM_LDFLAGS = $(LDFLAGS_NTP)

BUILT_SOURCES +=				\
	$(srcdir)/run-crypto.c			\
	$(srcdir)/run-keyFile.c			\
	$(srcdir)/run-kodDatabase.c		\
	$(srcdir)/run-kodFile.c			\
	$(srcdir)/run-networking.c		\
	$(srcdir)/run-packetProcessing.c	\
	$(srcdir)/run-utilities.c		\
	$(srcdir)/run-packetHandling.c		\
	$(NULL)

test_networking_SOURCES =		\
	networking.c			\
	run-networking.c		\
	$(top_builddir)/version.c	\
	$(NULL)

test_packetHandling_SOURCES =		\
	packetHandling.c		\
	run-packetHandling.c		\
	$(top_builddir)/version.c	\
	$(NULL)

test_kodDatabase_SOURCES =		\
	kodDatabase.c			\
	run-kodDatabase.c		\
	$(top_builddir)/version.c	\
	$(NULL)

test_keyFile_SOURCES =			\
	keyFile.c			\
	run-keyFile.c			\
	fileHandlingTest.c		\
	$(top_builddir)/version.c	\
	$(NULL)

test_kodFile_SOURCES =			\
	kodFile.c			\
	run-kodFile.c			\
	$(top_builddir)/version.c	\
	fileHandlingTest.c		\
	$(NULL)

test_packetProcessing_SOURCES =		\
	packetProcessing.c		\
	run-packetProcessing.c		\
	sntptest.c			\
	$(NULL)

test_utilities_SOURCES =		\
	utilities.c			\
	run-utilities.c			\
	fileHandlingTest.c		\
	$(NULL)

test_crypto_SOURCES =			\
	crypto.c			\
	run-crypto.c			\
	$(top_builddir)/version.c	\
	$(NULL)


$(srcdir)/run-kodFile.c: $(srcdir)/kodFile.c $(std_unity_list)
	$(run_unity) kodFile.c run-kodFile.c

$(srcdir)/run-keyFile.c: $(srcdir)/keyFile.c $(std_unity_list)
	$(run_unity) keyFile.c run-keyFile.c

$(srcdir)/run-kodDatabase.c: $(srcdir)/kodDatabase.c $(std_unity_list)
	$(run_unity) kodDatabase.c run-kodDatabase.c

$(srcdir)/run-networking.c: $(srcdir)/networking.c $(std_unity_list)
	$(run_unity) networking.c run-networking.c

$(srcdir)/run-packetProcessing.c: $(srcdir)/packetProcessing.c $(std_unity_list)
	$(run_unity) packetProcessing.c run-packetProcessing.c

$(srcdir)/run-packetHandling.c: $(srcdir)/packetHandling.c $(std_unity_list)
	$(run_unity) packetHandling.c run-packetHandling.c

$(srcdir)/run-utilities.c: $(srcdir)/utilities.c $(std_unity_list)
	$(run_unity) utilities.c run-utilities.c

$(srcdir)/run-crypto.c: $(srcdir)/crypto.c $(std_unity_list)
	$(run_unity) crypto.c run-crypto.c

#$(srcdir)/../version.c: $(srcdir)/../version.c
#	gcc -o version.o ../version.c

TESTS = 

if !NTP_CROSSCOMPILE
TESTS += $(check_PROGRAMS)
endif
#if !NTP_CROSSCOMPILE
#TESTS += tests-runner
#endif

## ensure ../libsntp.a is built

BUILT_SOURCES	+= check-libsntp
CLEANFILES	+= check-libsntp

check-libsntp: ../libsntp.a
	@echo stamp > $@

../libsntp.a:
	cd .. && $(MAKE) $(AM_MAKEFLAGS) libsntp.a

## check-libntp.mf - automake fragment
## slightly adapted for deeper directory

BUILT_SOURCES	+= check-libntp check-libunity
CLEANFILES	+= check-libntp	check-libunity

check-libntp: ../../libntp/libntp.a
	@echo stamp > $@

../../libntp/libntp.a:
	cd ../../libntp && $(MAKE) $(AM_MAKEFLAGS) libntp.a

check-libunity: ../unity/libunity.a
	@echo stamp > $@

../unity/libunity.a:
	cd ../unity && $(MAKE) $(AM_MAKEFLAGS) libunity.a

include $(top_srcdir)/depsver.mf
include $(top_srcdir)/includes.mf
