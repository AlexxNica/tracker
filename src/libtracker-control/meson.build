sources = ['tracker-miner-manager.c']

libtracker_control = library('tracker-control', sources,
    dependencies: tracker_miner_dep,
    c_args: '-DTRACKER_COMPILATION'
)

tracker_control_dep = declare_dependency(
    link_with: libtracker_control,
    dependencies: tracker_miner_dep
)
