KnnAM
=====

This is a implementation of KNN based acoustic models using GPUs for ASR

## Problem Statement
Given a set of preprocessed frames of audio in a transformed feature space
with their label, determine the log likelihood of a new frame in the label
space.

## Implementation
I have implemented a KNN based AM and log likelihood generator indirectly
based on the papers,


* Speech Recognition With State-based Nearest Neighbour Classifiers. Thomas
  Deselaer et al., Interspeech 2007.
* Garcia, V.; Debreuve, E.; Barlaud, M., "Fast k nearest neighbor search
  using GPU," Computer Vision and Pattern Recognition Workshops, 2008. CVPRW
  '08. IEEE Computer Society Conference on , vol., no., pp.1,6, 23-28 June
  2008

This implementation makes use of Nvidia's CUDA platform and the Thrust
Libraries for parallelization of the KNN computation. Also, it uses Boost
libraries for parsing input files 

## Current Status:
* DONE: classes and functions related to obtaining the data from a pFile format
have been written, but not tested
* TODO: Makefiles need to be written
* TODO: Test above classes for functionality and accuracy
* TODO: write wrapper for new pFile format










