sources = [
    'tracker-main.c',
    'tracker-miner-rss.c',
]

executable('tracker-miner-rss', sources,
    dependencies: [libgrss, tracker_miner_dep, tracker_extract_dep],
    c_args: [
        '-DTRACKER_COMPILATION',
    ],
)

#install_data(
#    sources: 'tracker-miner-files-index.xml',
#    install_dir: join_paths(get_option('datadir'), 'tracker'))
