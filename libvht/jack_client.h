/* jack_client.h
 *
 * Copyright (C) 2017 Remigiusz Dybka
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __JACK_CLIENT_H__
#define __JACK_CLIENT_H__

#include <jack/jack.h>

#define JACK_CLIENT_NAME 		"valhalla"
#define JACK_CLIENT_MAX_PORTS	16

jack_client_t *jack_client;
jack_port_t *jack_input_port;
extern jack_port_t *jack_output_ports[];
int jack_n_output_ports;
jack_status_t jack_status;
jack_nframes_t jack_sample_rate;
jack_nframes_t jack_buffer_size;
extern char *jack_error;

int jack_start(char *clt_name);
void jack_stop();
void jack_synch_n_output_ports();

#endif //__JACK_CLIENT_H__