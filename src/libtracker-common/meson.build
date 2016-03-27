enums = gnome.mkenums('tracker-enum-types',
    sources: 'tracker-enums.h',
    c_template: 'tracker-enum-types.c.template',
    h_template: 'tracker-enum-types.h.template',
)

tracker_common_sources = [
    'tracker-date-time.c',
    'tracker-dbus.c',
    'tracker-file-utils.c',
    'tracker-ioprio.c',
    'tracker-log.c',
    'tracker-sched.c',
    'tracker-type-utils.c',
    'tracker-utils.c',
    'tracker-locale.c',
    'tracker-parser-utils.c',
    'tracker-language.c',
    enums[0], enums[1],
]

if unicode_library_name == 'icu'
    tracker_common_sources += 'tracker-parser-libicu.c'
else
    tracker_common_sources += 'tracker-parser-libunistring.c'
endif

# FIXME: need to link against -lkvm on OpenBSD, see configure.ac
tracker_common_dependencies = [gio, gio_unix, glib, libmath]

libtracker_common = library('tracker-common',
    tracker_common_sources,
    dependencies: tracker_common_dependencies + [unicode_library],
    c_args: [
        '-DTRACKER_COMPILATION',
    ],
    include_directories: [configinc, srcinc],
    install_dir: get_option('libdir') + '/tracker-' + tracker_api_version,
)

tracker_common_dep = declare_dependency(
    sources: enums[1],
    link_with: libtracker_common,
    dependencies: tracker_common_dependencies,
    include_directories: [configinc, srcinc, include_directories('.')],
)
