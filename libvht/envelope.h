/* envelope.h - Valhalla Tracker
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

#ifndef __ENVELOPE_H__
#define __ENVELOPE_H__
#include <pthread.h>

typedef struct env_node_t {
	float x;
	float y;
	int helper;
	int link_to_prev;
} env_node;

typedef struct envelope_t {
	int nnodes;
	env_node *nodes;
	pthread_mutex_t excl;
} envelope;

envelope *envelope_new();
void envelope_free(envelope *env);
void envelope_del_node(envelope *env, int n);
void envelope_add_node(envelope *env, float x, float y, int helper, int linked);
void envelope_set_node(envelope *env, int n, float x, float y, int helper, int linked);

#endif //__ENVELOPE_H__
