/* XMRig
 * Copyright (c) 2018-2020 SChernykh   <https://github.com/SChernykh>
 * Copyright (c) 2016-2020 XMRig       <https://github.com/xmrig>, <support@xmrig.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef XMRIG_CHRONO_H
#define XMRIG_CHRONO_H


#include <chrono>


namespace xmrig {


	class Chrono
	{
	public:
		static inline uint64_t highResolutionMSecs()
		{
			using namespace std::chrono;

			return static_cast<uint64_t>(time_point_cast<milliseconds>(high_resolution_clock::now()).time_since_epoch().count());
		}


		static inline uint64_t steadyMSecs()
		{
			using namespace std::chrono;
			if (high_resolution_clock::is_steady) {
				return static_cast<uint64_t>(time_point_cast<milliseconds>(high_resolution_clock::now()).time_since_epoch().count());
			}

			return static_cast<uint64_t>(time_point_cast<milliseconds>(steady_clock::now()).time_since_epoch().count());
		}


		static inline uint64_t currentMSecsSinceEpoch()
		{
			using namespace std::chrono;

			return static_cast<uint64_t>(time_point_cast<milliseconds>(system_clock::now()).time_since_epoch().count());
		}
	};



	class Stopwatch {
	public:
		Stopwatch(bool startNow = false) {
			reset();
			if (startNow) {
				start();
			}
		}
		void reset() {
			isRunning = false;
			elapsed = 0;
		}
		void start() {
			if (!isRunning) {
				startMark = std::chrono::high_resolution_clock::now();
				isRunning = true;
			}
		}
		void restart() {
			startMark = std::chrono::high_resolution_clock::now();
			isRunning = true;
			elapsed = 0;
		}
		void stop() {
			if (isRunning) {
				chrono_t endMark = std::chrono::high_resolution_clock::now();
				uint64_t ns = std::chrono::duration_cast<sw_unit>(endMark - startMark).count();
				elapsed += ns;
				isRunning = false;
			}
		}
		double getElapsed() const {
			return getElapsedNanosec() / 1e+9;
		}


		uint64_t getElapsedNanosec() const {
			uint64_t elns = elapsed;
			if (isRunning) {
				chrono_t endMark = std::chrono::high_resolution_clock::now();
				uint64_t ns = std::chrono::duration_cast<sw_unit>(endMark - startMark).count();
				elns += ns;
			}
			return elns;
		}
	private:
		using chrono_t = std::chrono::high_resolution_clock::time_point;
		using sw_unit = std::chrono::nanoseconds;
		chrono_t startMark;
		uint64_t elapsed;
		bool isRunning;

	};


} /* namespace xmrig */

#endif /* XMRIG_CHRONO_H */
