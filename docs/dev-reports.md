<!--
============================================================
GUIDELINES
============================================================

1. Always log your changes before committing :
   - Record all meaningful changes you made within the project folder.
2. Add new reports at the top, not the bottom :
   - Always insert your entry right below this "GUIDELINES", "EXAMPLE" and "SUMMARY" section, so the latest updates appear first.
   - This keeps reports easy to review without endless scrolling and ensures the guide remains untouched at the top.
3. Keep it short, clear, and specific :
   - Each line should describe one clear change, avoid long paragraphs.
   - These notes help create accurate changelogs later.
4. Use one section per person per day :
   - Do not repeat your name or date multiple times.
   - All your daily changes go under your name for that day.
5. Follow a consistent format :
   - Start each report with today’s date and day as the main heading.
   - Use this date format : "Oct 06, 2025 - Monday" (include a leading zero for single-digit days).
   - Add your name as a sub-heading.
   - Link your GitHub profile using "[<your_name>](<your_github_profile_link)" - no spaces required.
   - Keep your displayed name consistent (preferably your real name).
   - GitHub automatically redirects if your username changes in future.
6. Keep your tone natural, not formal :
   - Write like you’re updating teammates - short, honest, and easy to read.
7. Contribute honestly and regularly :
   - This log ensures visibility and shared accountability among all team members.



============================================================
EXAMPLE
============================================================
## Aug 20, 2025 (Wednesday)
#### [Dev_1](https://github.com/user_is_1)
- Created project folder structure (`src/`, `packages/`, `docs/`, `builds/`).
- Added initial version of `index.js` and helper functions for core logic.
- Set up `.gitignore` and repository initialization.

#### [Dev_2](https://github.com/user_is_2)
- Wrote the initial `README.md` overview for public readability.  
- Created the “How It Works” section in documentation.

#### [Dev_3](https://github.com/user_is_3)
- Drafted documentation outline in `docs/overview.md`.
- Prepared visual guide for project's conceptual workflow.



============================================================
SUMMARY
============================================================
- Add new entries immediately below this section, newest on top.
- Use bullet points (–) for each change.
- Skip days you didn’t work — no empty placeholders.
- Never edit or move this "Guidelines", "Example" or "Summary" section.
-->
## 🗞️ <font color="#e36c09">Nov 5, 2025 - Wednesday</font>
#### [Uday](https://github.com/udaysh134)
- Added `CONTRIBUTORS.md` file in the root directory.
- Included structured tables for "Core Team" and "Other Contributors" with dynamic GitHub avatars.
- Added contributor guidelines and acknowledgment section for future maintainers.
- Finalized Markdown formatting and layout for readability and professionalism.
- Added “**Meet the Contributors**” section in `README.md`.
- Integrated clickable GitHub profile avatars of the Core Team with inline styles for rounded corners.
- Linked to the detailed `CONTRIBUTORS.md` file for full roles and acknowledgments.
- Ensured consistent avatar sizing and alignment for clean visual balance.


## 🗞️ <font color="#e36c09">Nov 1, 2025 - Saturday</font>
#### [Uday](https://github.com/udaysh134)
- Defined the main DB path as a global variable in `user.c` for easier updates and maintenance.
- Added a new condition in `checkUsername()` to handle error code 3 from `searchDir()` function.
- Completed basic testing of `searchDir()`’s "**List**" mode; all returned data verified successfully.


## 🗞️ <font color="#e36c09">Oct 31, 2025 - Friday</font>
#### [Uday](https://github.com/udaysh134)
- Added a new functionality : "Mode" parameter in `searchDir()` to allow two operations — searching a specific file/folder by name or listing all contents within a directory.
- Refactored the entire function logic to support both modes and documented clear usage instructions for developers.
- Reordered parameters name and mode for better readability and consistency.
- Updated struct in `utils.h` to include new fields : `names` and `count`.
- Modified `searchDir()` implementation in `user.c` to align with the updated structure.
- Verified the function in `optSignIn()` using the "List" mode for successful testing.


## 🗞️ <font color="#e36c09">Oct 30, 2025 - Thursday</font>
#### [Uday](https://github.com/udaysh134)
- Integrated and refactored `password.c` to create a reusable `maskInput()` function in `utils.c` for terminal input masking.
- Updated related declarations and logic in `utils.h` and `utils.c`.
- Fixed the `scanf()` issue in `optSigIn()` and added a "**switch**" case structure to continue sign-in logic development.
- Integrated `maskInput()` in `admin.c` to securely handle hidden passcode input.
- Cleaned up formatting and minor issues across multiple files.
- Removed `password.c` since its functionality was merged into the new `maskInput()` function.
- Fixed few bugs and did some formatting in files like `launch.c`, `user.c` and `utils.c`.


## 🗞️ <font color="#e36c09">Oct 29, 2025 - Wednesday</font>
#### [Uday](https://github.com/udaysh134)
- Fixed re-execution issue in `launch()` by adding "return" statements at lines 33 and 36 in `launch.c`.
- Completed `checkUsername()` function in `user.c` to enable progression in `optSignIn()` and `optSignUp()` functions.
- Updated `optSignIn()` and `optSignUp()` to accept a string parameter, allowing continuation from the ending of `checkUsername()` function.
- Continued refining `optSignIn()` function to improve logic and progress toward completion.


## 🗞️ <font color="#e36c09">Oct 28, 2025 - Tuesday</font>
#### [Uday](https://github.com/udaysh134)
- Updated `searchDir()` function in `utils.h` to return a `struct` instead of `void`.
- Reimplemented `searchDir()` in `utils.c` to return both status code (0/1/2) and the found file/folder name.
- Tested the updated function in `user.c` using a relative path and other custom parameters.


## 🗞️ <font color="#e36c09">Oct 27, 2025 - Monday</font>
#### [Uday](https://github.com/udaysh134)
- Reformatted `README.md` to fix bold text inconsistencies caused by HTML spacing issues.
- Completed `searchDir()` function to dynamically locate a **file** or a **folder** by "_name_" and "_path_" from any directory.
- Enhanced `searchDir()` function with parameters - "_path_", "_type_" and "_name_" for maximum accessibility and flexibility in future file and folder searches.
- Worked on finishing off the **User Panel** - added `validateUsername()` function, tested `searchDir()` function and followed internal guidelines for proceeding on the User Panel functionality.
- Added new mockup images in `assets/designs`.
- Updated layout of `README.md` with new `<div>` tags to display mockups of both Light and Dark mode side-by-side.


## 🗞️ <font color="#e36c09">Oct 26, 2025 - Sunday</font>
#### [Uday](https://github.com/udaysh134)
- Edited [Yazdaan](https://github.com/SenorDan031)’s **Oct 25th** "dev-report" for improved readability and consistency.
- Replaced `<p>` tags with `<div>` tags in the main `README.md` to properly center headings and enhance layout alignment.
- Created and added Fluix's concept's mockup images in `README.md` to better convey the sense of the project with clear visuals.
- Removed "Example Layout" from "**Demo Preview (Concept UI)**" section as it was no longer needed.
- Created `assets` directory with `/designs` and `/sketches` subfolders for organizing concept visuals.
- Added images inside `assets/sketches` and `assets/designs` to use them inside `README.md` for display.
- Created `/packages` folder in `src/backend` to store external libraries for better portability.
- Added **cJSON** library (`cJSON.c/h`) inside `packages/cJSON` to remove dependency on external installation.
- Moved all `.c` files from `src/backend/include` to `src/backend/src` for cleaner structure and maintainability; only header files remain in `/include`.
- Relocated `searcher.c` to `src/backend/tests` since it’s not yet part of the main executable build.
- Edited `Makefile` to reflect all new directory changes.


## 🗞️ <font color="#e36c09">Oct 25, 2025 - Saturday</font>
#### [Uday](https://github.com/udaysh134)
- Completed full rewrite and expansion of the main project `README.md`.
- Replaced placeholder description with complete structured documentation.
- Added sections for overview, current progress, vision, demo preview, and team info.
- Documented implemented backend systems, upcoming goals, and concept UI layout.
- Added badges below the “**Fluix**” title for better readability and quick access to key info.
#### [Yazdaan](https://github.com/SenorDan031)
- Added `SEARCH Y (COPY).c` in `src/backend/tests` and `searcher.c` in `src/backend/include`.
- Completed search function to retrieve answers from user input queries.
- Added `dbstruct002.json` in `src/backend/tests` to include usable data to run tests for searching.


## 🗞️ <font color="#e36c09">Oct 15, 2025 - Wednesday</font>
#### [Uday](https://github.com/udaysh134)
- Resized `Fluix Logo.png` to maintain a 1:1 ratio for consistent display across the site.
- Added `Fluix Logo.png` as the favicon in the head section of `index.html` and extended title of the page.


## 🗞️ <font color="#e36c09">Oct 14, 2025 - Tuesday</font>
#### [Japnoor](https://github.com/kaurjapnoor60-max)
- Added a hover effect over **Sign In** button with "transform" and "shadow" properties.
- Added "**Fluix**" logo as header on the webpage - modified `index.html` and `style.css` accordingly.
#### [Uday](https://github.com/udaysh134)
- Logged a missing entry from [Japnoor](https://github.com/kaurjapnoor60-max) - hover effect over **Sign In** button.
- Added detailed instructions in `user.c` for building the main core of the User Panel and its functionalities.
- Added `/css`, `/js`, and `/pages` folders inside `src/frontend/src/` to organize the frontend structure and relocated files accordingly.
- Formatted and organized `index.html` and `style.css`, fixing indentations and spacing for a cleaner code structure.
- Re-wrote [Chirag](https://github.com/chirag88533)'s log more precisely to maintain consistency.
- Logged a missing entry from [Japnoor](https://github.com/kaurjapnoor60-max) - addition of "Fluix" logo.
- Renamed `FLUIX logo 3RG.png` to `Fluix Logo.png` and moved it into `../assets/images/` to maintain an organization.
- Fixed relative path of `Fluix Logo.png` in `index.html` to ensure proper file tracking.
- Re-formatted `index.html` and `style.css` to fix indentations and unnecessary spaces.
- Fixed oversized Fluix logo issue causing it to dominate the screen layout.
#### [Chirag](https://github.com/chirag88533)
- Made few changes in `search_C1.c`, which enabled explicit user input for searching a term from a file.


## 🗞️ <font color="#e36c09">Oct 13, 2025 - Monday</font>
#### [Uday](https://github.com/udaysh134)
- Formatted header declarations in `utils.c`, `user.c`, `launch.c`, and `admin.c` for consistency across all files.
- Added option containers in `launch.c` and `user.c` to simplify future option additions.
- Extended functionality of `user.c` to match the display style used across the project.
- Opened groundwork in `user.c` to enable addition of new functions and upcoming features.
- Updated `user.c` to follow a new structure to initiate user verification (incomplete though).
- Added "*checkUsername*", "*optSignIn*", "*optSignUp*" functions in `user.c` with instructions.
- Declared "*searchDir*" function in `utils.c/h`.
- Logged missing entry from [Kashish](https://github.com/kash-12) - extended `index.html` & `style.css`.
#### [Chirag](https://github.com/chirag88533)
- Added `search_C1.c` in `src/backend/tests`, to search through entries in a `.json` file.
#### [Kashish](https://github.com/kash-12)
- Enhanced frontend by adding a "Sign In" box - updated `index.html` and `style.css` accordingly.


## 🗞️ <font color="#e36c09">Oct 12, 2025 - Sunday</font>
#### [Uday](https://github.com/udaysh134)
- Updated `activity-records.md` with another day of discussion and tasks assigned.
- Logged missing update from [Chirag](https://github.com/chirag88533) - added `proto_C1.c`.
#### [Chirag](https://github.com/chirag88533)
- Added `proto_C1.c` to extend functionality of [Manikant](https://github.com/manikant12aggi)'s `proto_m1.c` for removing entries from `.json` files.


## 🗞️ <font color="#e36c09">Oct 11, 2025 - Saturday</font>
#### [Uday](https://github.com/udaysh134)
- Added "**time**" key in `dbStruct.json` with value as an object, containing timestamps for creation and modification of that Q&A block.


## 🗞️ <font color="#e36c09">Oct 10, 2025 - Friday</font>
#### [Uday](https://github.com/udaysh134)
- Added a sample file `dbStruct.json` in `src/backend/tests` to provide a structure for Q&As to the backend team.


## 🗞️ <font color="#e36c09">Oct 09, 2025 - Thursday</font>
#### [Uday](https://github.com/udaysh134)
- Logged all missing updates from yesterday ([Japnoor](https://github.com/kaurjapnoor60-max)'s and [Manikant](https://github.com/manikant12aggi)'s additions to the repository).
- Updated `activity-records.md` with **Oct 08, 2025** team discussion logs.
- Reformatted `activity-records.md` to match formatting style of other `.md` files from the repo, for consistency.
- Reformatted `password.c` and `proto_m1.c` with clean spaces and sections, no functional changes.


## 🗞️ <font color="#e36c09">Oct 08, 2025 - Wednesday</font>
#### [Uday](https://github.com/udaysh134)
- Logged a missed update from yesterday (`password.c` - test for terminal password masking).
- Removed redundant headers from `activity-reports.md` and `update-logs.md`.
- Updated `activity-records.md` with **Oct 07, 2025** team discussion logs.
#### [Japnoor](https://github.com/kaurjapnoor60-max)
- Added content in `index.html` and file `style.css` under `src/frontend`to start building a landing page for Fluix.
#### [Manikant](https://github.com/manikant12aggi)
- Added file `proto_m1.c` in `backend/tests` for testing removal of content from `.txt` files.


## 🗞️ <font color="#e36c09">Oct 07, 2025 - Tuesday</font>
#### [Yazdaan](https://github.com/SenorDan031)
- Added `password.c` in `src/backend/tests` for terminal password masking functionality.