#include <stdio.h>
#include "jack_client.h"
#include "jack_process.h"

#include "libpms.h"
#include "module.h"

int start() {
    return jack_start();
}

void stop() {
    jack_stop();
}

int module_get_bpm() {
    return module.bpm;
}

void module_set_bpm(int bpm) {
    module.bpm = bpm;
}

int get_nseq(void) {
    return module.nseq;
}

void module_play(int play) {
    module.playing = play;
    if (play == 0)
        module_mute();
}

int module_is_playing() {
    return module.playing;
}

void module_reset() {
    module.seq[0]->pos = 0;
    module.zero_time = 0;
    for (int t = 0; t < module.seq[0]->ntrk; t++)
        track_reset(module.seq[0]->trk[t]);
}

struct module_t *get_module() {
    return &module;
}

int module_get_nseq(void) {
    return module.nseq;
}

sequence *module_get_seq(int n) {
    return module.seq[n];
}

int sequence_get_ntrk(sequence *seq) {
    return seq->ntrk;
}

track *sequence_get_trk(sequence *seq, int n) {
    return seq->trk[n];
}

row *track_get_row_ptr(track *trk, int c, int r) {
    return &trk->rows[c][r];
}

int track_get_length(track *trk) {
    return trk->nrows;
}

int track_get_ncols(track *trk) {
    return trk->ncols;
}

int track_get_port(track *trk) {
    return trk->port;
}

int track_get_channel(track *trk) {
    return trk->channel;
}

int track_get_nrows(track *trk) {
    return trk->nrows;
}

int track_get_nsrows(track *trk) {
    return trk->nsrows;
}

int track_get_playing(track *trk) {
    return trk->playing;
}

double track_get_pos(track *trk) {
    return trk->pos;
}

void track_set_port(track *trk, int n) {
    trk->port = n;
}

void track_set_channel(track *trk, int n) {
    trk->channel = n;
}

void track_set_nrows(track *trk, int n) {
    trk->nrows = n;
}

void track_set_nsrows(track *trk, int n) {
    trk->nsrows = n;
}


