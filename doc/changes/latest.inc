.. NOTE: we are now using links to highlight new functions and classes.
   Please follow the examples below like :func:`mne.stats.f_mway_rm`, so the
   whats_new page will have a link to the function/class documentation.

.. NOTE: there are 3 separate sections for changes, based on type:
   - "Enhancements" for new features
   - "Bugs" for bug fixes
   - "API changes" for backward-incompatible changes

.. NOTE: changes from first-time contributors should be added to the TOP of
   the relevant section (Enhancements / Bugs / API changes), and should look
   like this (where xxxx is the pull request number):
   - description of enhancement/bugfix/API change (:gh:`xxxx` **by new contributor** |Firstname Lastname|_)

.. _current:

Current (0.23.dev0)
-------------------

.. |New Contributor| replace:: **New Contributor**

.. |Anna Padee| replace:: **Anna Padee**

.. |Richard Koehler| replace:: **Richard Koehler**

.. |Zhi Zhang| replace:: **Zhi Zhang**

.. |Andres Rodriguez| replace:: **Andres Rodriguez**

.. |Matt Sanderson| replace:: **Matt Sanderson**

.. |Enrico Varano| replace:: **Enrico Varano**

.. |Dominik Welke| replace:: **Dominik Welke**

.. |Judy D Zhu| replace:: **Judy D Zhu**

Enhancements
~~~~~~~~~~~~
- New Tutorial for analyzing frequency-tagging data (:gh:`8867` **by new contributor** |Dominik Welke|_ and `kalenkovich`_)

- Add dbs as new channel type for deep brain stimulation (DBS) recordings (:gh:`8739` **by new contributor** |Richard Koehler|_)

- Add :func:`mne.chpi.extract_chpi_locs_kit` to read cHPI coil locations from KIT/Yokogawa data (:gh:`` **by new contributor** |Matt Sanderson|_, `Robert Seymour`_, and `Eric Larson`_)

- Add ``match_alias`` parameter to :meth:`mne.io.Raw.set_montage` and related functions to match unrecognized channel location names to known aliases (:gh`8799` **by new contributor** |Zhi Zhang|_)

- Update the ``notebook`` 3d backend to use ``ipyvtk_simple`` for a better integration within ``Jupyter`` (:gh:`8503` by `Guillaume Favelier`_)

- Remove the 15-character limitation for channel names when writing to FIF format. If you need the old 15-character names, you can use something like ``raw.rename_channels({n: n[:13] for n in raw.ch_names}, allow_duplicates=True)``, by `Eric Larson`_ (:gh:`8346`)

- Add channel-specific annotation support to :class:`mne.Annotations` via ``ch_names`` parameter (:gh:`8896` by `Eric Larson`_)

- Add toggle-all button to :class:`mne.Report` HTML and ``width`` argument to :meth:`mne.Report.add_bem_to_section` (:gh:`8723` by `Eric Larson`_)

- Add infant template MRI dataset downloader :func:`mne.datasets.fetch_infant_template` (:gh:`8738` by `Eric Larson`_ and `Christian O'Reilly`_)

- Add digitizer information to :func:`mne.io.read_raw_egi` (:gh:`8789` by `Christian Brodbeck`_)

- Allow reading digitization from files other than ``*.fif`` in the coregistration GUI (:gh:`8790` by `Christian Brodbeck`_)

- Speed up :func:`mne.inverse_sparse.tf_mixed_norm` using STFT/ISTFT linearity (:gh:`8697` by `Eric Larson`_)

- Reduce memory consumption of `mne.io.Raw` and speed up epoching when thousands of events are present for `mne.Epochs` (:gh:`8801` by `Eric Larson`_)

- Speed up ``import mne`` by reducing function creation overhead (:gh:`8829` by `Eric Larson`_)

- `mne.Report.parse_folder` now processes supported non-FIFF files by default, too (:gh:`8744` by `Richard Höchenberger`_)

- `mne.Report` has gained a new method `~mne.Report.add_custom_css` for adding user-defined styles (:gh:`8762` by `Richard Höchenberger`_)

- Add option to control appearance of opaque inside surface of the head to :ref:`mne coreg` (:gh:`8793` by `Eric Larson`_)

- Add support for non-FIF files in :ref:`mne browse_raw` using :func:`mne.io.read_raw` (:gh:`8806` by `Eric Larson`_)

- Add :func:`mne.io.read_raw_nedf` for reading StarStim / enobio NEDF files (:gh:`8734` by `Tristan Stenner`_)

- Add :meth:`raw.describe() <mne.io.Raw.describe>` to display (or return) descriptive statistics for each channel (:gh:`8760` by `Clemens Brunner`_)

- Add :meth:`annotations.to_data_frame() <mne.Annotations.to_data_frame>` to return annotations as a pandas dataframe (:gh:`8783` by `Robert Luke`_)

- Add :func:`mne.preprocessing.compute_maxwell_basis` to compute the SSS basis function (:gh:`8822` by `Eric Larson`_)

- Add the ``silhouette`` parameter to :class:`mne.viz.Brain` to display sharp edges and improve perception (:gh:`8771` by `Guillaume Favelier`_)

- Add warning to :func:`mne.cov.compute_whitener` when an explicit ``rank`` parameter leads to a large increase in condition number (:gh:`8805` by `Eric Larson`_)

- Add parameter ``align=True`` to `mne.viz.Brain.show_view` to make views relative to the closest canonical (MNI) axes rather than the native MRI surface RAS coordinates (:gh:`8794` by `Eric Larson`_)

- Add ``auto_close`` to `mne.Report.add_figs_to_section` and `mne.Report.add_slider_to_section` to manage closing figures (:gh`8730` by `Guillaume Favelier`_)

- Add :func:`mne.write_head_bem` to support writing head surface files (:gh:`8841` by `Yu-Han Luo`_)

- The signal of ``resp`` (respiratory) channels is now assumed to be in the unit Volt  (:gh:`8858` by `Richard Höchenberger`_)

- Static type checkers like Pylance (comes with VS Code) now display the parameters of many more functions correctly, largely improving overall usability for VS Code users (:gh:`8862` by `Richard Höchenberger`_)

- Support new EEGLAB file format (:gh:`8874` by `Clemens Brunner`_)

- Reading and writing FIFF files whose filenames end with ``_meg.fif.gz``, ``_eeg.fif(.gz)``, and ``_ieeg.fif(.gz)`` doesn't emit a warning anymore; this improves interobaility with BIDS-formatted datasets (:gh:`8868` by `Richard Höchenberger`_)

- On macOS, we now set the environment variable ``QT_MAC_WANTS_LAYER`` to ``"1"`` if it hasn't been set explicitly by the user, in order to ensure that `~mne.SourceEstimate` plots work on macOS 11 with older versions of Qt and PyQt (:gh:`8959` by `Richard Höchenberger`_)

- :func:`mne.time_frequency.EpochsTFR.average` now allows different ways of averaging, such as "median", or callable functions (:gh:`8879` by `Adam Li`_)

- `~mne.Epochs` metadata can now be generated automatically from events using `mne.epochs.make_metadata` (:gh:`8834` by `Richard Höchenberger`_)

- Interactions with sliders in `mne.Report` will now continuously update the linked content (it was updated only on mouse button release before) (:gh:`9023` by `Richard Höchenberger`_)

Bugs
~~~~
- Fix bug with :func:`mne.io.read_raw_kit` where missing marker coils were not handled (:gh:`8989` **by new contributor** |Judy D Zhu|_)

- Fix bug with `mne.connectivity.spectral_connectivity` where time axis in Epochs data object was dropped. (:gh:`8839` **by new contributor** |Anna Padee|_)

- Fix bug with `mne.io.Raw.resample` to allow passing ``stim_picks='misc'`` (:gh:`8844` **by new contributor** |Enrico Varano|_ and `Eric Larson`_)

- Fix bugs with `mne.io.read_raw_persyst` where multiple ``Comments`` with the same name are allowed, and ``Comments`` with a "," character are now allowed (:gh:`8311` and :gh:`8806` **by new contributor** |Andres Rodriguez|_ and `Adam Li`_)

- Fix zen mode and scalebar toggling for :meth:`raw.plot() <mne.io.Raw.plot>` when using the ``macosx`` matplotlib backend (:gh:`8688` by `Daniel McCloy`_)

- Fix bug with :func:`mne.viz.snapshot_brain_montage` where the positions were incorrect (:gh:`8983` by `Eric Larson`_)

- Fix bug with :func:`mne.preprocessing.maxwell_filter` where the eSSS basis had to exactly match the good channels instead of being a superset (:gh:`8675` by `Eric Larson`_)

- Fix bug with :meth:`mne.Report.add_bem_to_section` where ``n_jobs != 1`` would cause ``n_jobs`` subsets of MRI images in some orientations to be flipped (:gh:`8713` by `Eric Larson`_)

- Fix bug with :meth:`raw.plot() <mne.io.Raw.plot>` where annotations didn't immediately appear when changing window duration (:gh:`8689` by `Daniel McCloy`_)

- Fix bug with :meth:`raw.plot() <mne.io.Raw.plot>` where ``scalings='auto'`` did not compute scalings using the full range of data (:gh:`8806` by `Eric Larson`_)

- Fix bug with :meth:`raw.plot() <mne.io.Raw.plot>` where setting a ``lowpass`` could lead to non-data-channels not plotting (:gh:`8954` by `Eric Larson`_)

- Fix bug with :meth:`mne.io.Raw.load_data` and :meth:`mne.Epochs.drop_bad` where ``verbose`` logging was not handled properly (:gh:`8884` by `Eric Larson`_)

- Fix bug with :func:`mne.io.read_raw_nicolet` where header type values such as num_sample and duration_in_sec where not parsed properly (:gh:`8712` by `Alex Gramfort`_)

- Fix bug with :func:`mne.preprocessing.read_ica_eeglab` when reading decompositions using PCA dimensionality reduction (:gh:`8780` by `Alex Gramfort`_ and `Eric Larson`_)

- Fix bug with :func:`mne.minimum_norm.make_inverse_operator` where ``depth`` was errantly restricted to be less than or equal to 1. (:gh:`8804` by `Eric Larson`_)

- Fix bug with :func:`mne.stats.permutation_cluster_1samp_test` and related clustering functions when ``adjacency=None`` and ``out_type='indices'`` (:gh:`#8842` by `Eric Larson`_)

- Fix bug with :func:`mne.viz.plot_alignment` where plotting a sphere model could ignore the ``brain`` argument (:gh:`8857` by `Eric Larson`_)

- Fix bug with :meth:`mne.Annotations.save` where files could be overwritten accidentally, it can now be controlled via the ``overwrite`` argument (:gh:`8896` by `Eric Larson`_)

- Fix bug with ``replace`` argument of :meth:`mne.Report.add_bem_to_section` and :meth:`mne.Report.add_slider_to_section` (:gh:`8723` by `Eric Larson`_)

- Fix bug with :func:`mne.chpi.compute_chpi_locs` where all cHPI coils being off would lead to an empty array of the wrong dimensionality (:gh:`8956` by `Eric Larson`_)

- Fix compatibility bugs with :mod:`mne_realtime` (:gh:`8845` by `Eric Larson`_)

- Fix bug with `mne.viz.Brain` where non-inflated surfaces had an X-offset imposed by default (:gh:`8794` by `Eric Larson`_)

- Fix bug with :ref:`mne coreg` where nasion values were not updated when clicking (:gh:`8793` by `Eric Larson`_)

- Fix bug with matplotlib-based 3D plotting where ``Axes3D`` were not properly initialized in :func:`mne.viz.plot_source_estimates` (:gh:`8811` by `Chris Bailey`_)

- Allow sEEG channel types in :meth:`mne.Evoked.plot_joint` (:gh:`8736` by `Daniel McCloy`_)

- Fix bug where hidden annotations could be deleted interactively in :meth:`mne.io.Raw.plot` windows (:gh:`8831` by `Daniel McCloy`_)

- Function :func:`mne.set_bipolar_reference` was not working when passing ``Epochs`` constructed with some ``picks`` (:gh:`8728` by `Alex Gramfort`_)

- Fix anonymization issue of FIF files after IO round trip (:gh:`8731` by `Alex Gramfort`_)

- Fix bug in `mne.preprocessing.ICA.plot_sources` where right-clicking component names could yield `~mne.preprocessing.ICA.plot_properties` windows for the wrong component if ``picks`` had been specified (:gh:`8996` by `Daniel McCloy`_)

- Fix title not shown in :func:`mne.viz.plot_montage` (:gh:`8752` by `Clemens Brunner`_)

- `mne.io.read_raw_egi` now correctly handles `pathlib.Path` filenames (:gh:`8759` by `Richard Höchenberger`_)

- `mne.viz.plot_evoked` and `mne.Evoked.plot` now correctly plot global field power (GFP) for EEG data when ``gfp=True`` or ``gfp='only'`` is passed (used to plot RMS). For MEG data, we continue to plot the RMS, but now label it correctly as such (:gh:`8775` by `Richard Höchenberger`_)

- Fix bug with :ref:`mne make_scalp_surfaces` where ``--overwrite`` was not functional (:gh:`8800` by `Yu-Han Luo`_)

- Fix bug with :func:`mne.viz.plot_topomap` when plotting gradiometers with a missing channel in a pair (:gh:`8817` by `Alex Gramfort`_)

- :meth:`epochs.crop() <mne.Epochs.crop>` now also adjusts the ``reject_tmin`` and ``reject_tmax`` attributes if necessary (:gh:`8821` by `Richard Höchenberger`_)

- When creating `~mne.Epochs`, we now ensure that ``reject_tmin`` and ``reject_tmax`` cannot fall outside of the epochs' time interval anymore (:gh:`8821` by `Richard Höchenberger`_)

- `~mne.io.read_raw_bti` erroneously treated response channels as respiratory channels (:gh:`8855` by `Richard Höchenberger`_)

- The RMS trace shown in the time viewer of `~mne.SourceEstimate` plots is now correctly labeled as ``RMS`` (was ``GFP`` before) (:gh:`8965` by `Richard Höchenberger`_)

- Fix bug with :func:`mne.SourceEstimate.plot` and related functions where the scalars were not interactively updated properly (:gh:`8985` by `Eric Larson`_)

- Fix bug with mne.channels.find_ch_adjacency() returning wrong adjacency for Neuromag122-Data (:gh:`8891` by `Martin Schulz`_)

- Fix :func:`mne.read_dipole` yielding :class:`mne.Dipole` objects that could not be indexed (:gh:`8963` by `Marijn van Vliet`_)

API changes
~~~~~~~~~~~
- ``mne.read_selection`` has been deprecated in favor of `mne.read_vectorview_selection`. ``mne.read_selection`` will be removed in MNE-Python 0.24 (:gh:`8870` by `Richard Höchenberger`_)
