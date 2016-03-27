sources = [
    'tracker-config.c',
    'tracker-extract-watchdog.c',
    'tracker-main.c',
    'tracker-miner-files.c',
    'tracker-miner-files-index.c',
    'tracker-miner-files-peer-listener.c',
    'tracker-storage.c',
    'tracker-writeback-listener.c',
    'tracker-writeback-dispatcher.c',
    'tracker-writeback.c',
]

if battery_detection_library_name == 'upower'
  sources += 'tracker-power-upower.c'
elif battery_detection_library_name == 'hal'
  sources += 'tracker-power-hal.c'
endif

executable('tracker-miner-fs', sources,
    dependencies: [tracker_miner_dep, tracker_extract_dep],
    c_args: [
        '-DTRACKER_COMPILATION',
    ],
)

install_data(
    sources: 'tracker-miner-files-index.xml',
    install_dir: join_paths(get_option('datadir'), 'tracker'))
