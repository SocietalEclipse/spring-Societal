/*
	Copyright 2008  Nicolas Wu

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.

	@author Nicolas Wu
	@author Robin Vobruba <hoijui.quaero@gmail.com>
*/

#include "AIGlobalAI.h"

#include "ExternalAI/IGlobalAI.h"
#include "ExternalAI/IGlobalAICallback.h"

CAIGlobalAI::CAIGlobalAI() : CAIAI(), gai(NULL) {}

CAIGlobalAI::CAIGlobalAI(int teamId, IGlobalAI* gai)
		: CAIAI(teamId, gai), gai(gai) {}

CAIGlobalAI::~CAIGlobalAI() {
	// TODO: check: should this really be done here?
	delete gai;
	gai = NULL;
}

void CAIGlobalAI::InitAI(IGlobalAICallback* globalAICallback, int teamId) {
	gai->InitAI(globalAICallback, teamId);
}
