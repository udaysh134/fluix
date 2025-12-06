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
## 🗞️ <font color="#e36c09">Dec 6, 2025 - Saturday</font>
#### [Uday](https://github.com/udaysh134)
- Updated `CONTRIBUTORS.md` to reflect new change of team members.
- Moved [Chirag](https://github.com/chirag88533) from the "**Core Team**" section to "**Past Contributors**" section.
- Deleted `create_bot_exp0001.c` as it was created just for a test.


## 🗞️ <font color="#e36c09">Dec 3, 2025 - Wednesday</font>
#### [Uday](https://github.com/udaysh134)
- Renamed `dbStruct.json` to `dataSchema.json` for clearer purpose.
- Updated the data saving structure of `dataSchema.json` to include "**schemaVersion**" and "**bot**" metadata keys.
- Moved all entries under a single "**entries**" key and removed the "**time**" field to simplify future data fetching.
- Updated discussion and tasks of 2nd Dec 2025 in `activity-records.md`.


## 🗞️ <font color="#e36c09">Dec 2, 2025 - Tuesday</font>
#### [Uday](https://github.com/udaysh134)
- Removed leftover code from merge conflict in `user.c`.
- Fixed incorrect day labels in previous dev report headings.
- Removed [Yazdaan](https://github.com/SenorDan031)'s dev reports entries of 29th Nov as they weren't any real changes made in the code base. Purpose of `dev-reports.md` is to only track all changes made by anyone, responsibly by themselves.
- Rewrote [Yazdaan](https://github.com/SenorDan031)'s 30th Nov's dev entries for consistency.
- Created `validateUsername()` function from scratch with two added error handlings and better response system.
- Removed [Manikant](https://github.com/manikant12aggi)'s `optSignUp()` function's code as it was dysfunctional because of the 'while' loop.
- Moved [Yazdaan](https://github.com/SenorDan031)'s wrongly dated dev entries into the correct (Dec 02, 2025) section and formatted it for consistency.
- Created another function `userPanel()` in `user.c` to further divide module in readable and understandable code structure.
- Completed `optSignIn()` and `optSignUp()` functions, redirecting both into new `userPanel()` function.
- Added folder `./assets/flowcharts` with `.png` flowchart files to clarify and get a better understanding of backend process line.
- Finalized User Panel layout with working navigation options and fixed buffer overflow in `optSignUp()`.
- Updated `admin.c` with two new menu options and refactored `launch.c` to support the new streamlined navigation flow.
- Added parameter and `searchDir()` code to `userPanel()` to display username and available bots.
- Updated User Panel layout for consistent data formatting and presentation.
- Added a new menu option in User Panel for deleting the user account via switch-case.
- Added `deleteDir()` function in `utils.c` for removing folders recursively.
- Completed the `userPanel()` function in `user.c` with extra addition of 'delete my account' functionality.
- Added `data.c/h` as per the flowchart's plan, to continue code flow from `bot.c` to `data.c` and its functions.
- Moved `QNA.h` from `src/backend/include` to `src/backend/tests`, as everything will lead up to `bot.c` and `data.c`.
- Added `createBot()` and `accessBots()` functions as declarations in `bot.c/h`, as per the pre-mapped plan.
- Added `optView()`, `optAdd()`, `optEdit()` and `optDelete()` functions as declarations in `data.c/h`.
#### [Yazdaan](https://github.com/SenorDan031)
- Added more tag supports in `dbstruct002.json`.
- Renamed `dbstruct002.json` to `PSIT_INQ.json`.
- Fixed the alternate ID issue with the 'merge conflict' created in `bot.c/h`.


## 🗞️ <font color="#e36c09">Dec 1, 2025 - Monday</font>
#### [Uday](https://github.com/udaysh134)
- Updated `activity-records.md` with Discussion 10 and tasks for Nov 27, 2025.


## 🗞️ <font color="#e36c09">Nov 30, 2025 - Sunday</font>
#### [Yazdaan](https://github.com/SenorDan031)
- Updated `bot.c` with commented out code of sub-functions planned to be used later on.
- Added `bot.h` in `src/backend/include` directory.
- Added the pre-processor directive to enable importing of bot functions in `user.c`.
- Added `QNA.h` in `src/backend/include` directory.
- Renamed `SEARCH Y1.c` to `QNA.c` from `/tests` folder.
- Linked `Ask_Fluix()` function in `bot.c`.
- `QNA.h` and updates on files : `bot.c`, `user.c` and `QNA.c` were made by [Yazdaan](https://github.com/SenorDann)'s alternate ID, [SenorDann](https://github.com/SenorDann).


## 🗞️ <font color="#e36c09">Nov 27, 2025 - Thursday</font>
#### [Uday](https://github.com/udaysh134)
- Cleaned up unused and commented code from `isUser()` function.
- Removed `checkUsername()` and moved its logic directly into `isUser()` to reduce extra steps.
- Fixed misplaced Nov 27th logs by moving them from the Nov 26th section to the correct date in `dev-reports.md`.
- Refactored, reformatted and cleaned the code of `user.c` for clearer logic, expanding if-else code blocks.
- Shifted input checks and switch case handling logic from `optSignIn()` & `optSignUp()` to `isUser()` function.
- Added clear, structured instructions and improved documentation across `user.c`.
- Included `bot.c` in project's Makefile to avoid future incompatability.


## 🗞️ <font color="#e36c09">Nov 26, 2025 - Wednesday</font>
#### [Uday](https://github.com/udaysh134)
- Added a clearer navigation step in `checkUsername()` before calling `optSignUp()` function in `user.c`.
- The navigation system now first asks for the confirmation before jumping into the `optSignUp()` function.
- Added more instructions inside `optSignUp()` for better clarity.


## 🗞️ <font color="#e36c09">Nov 25, 2025 - Tuesday</font>
#### [Uday](https://github.com/udaysh134)
- Created `parseEnv()` function to parse env data dynamically.
- Removed `getEnvValue()`, `loadEnvFromFile()` and related sub-functions to replace them with `parseEnv()`.
- Adjusted and fixed code in `admin.c` to use new `parseEnv()` and optimized some code logic.
- Removed commented section from [Yazdaan](https://github.com/SenorDan031) in `admin.c` and `main.c`.
- Reformatted [Yazdaan](https://github.com/SenorDan031)'s logs for consistency.


## 🗞️ <font color="#e36c09">Nov 24, 2025 - Monday</font>
#### [Yazdaan](https://github.com/SenorDan031)
- Created `getEnvValue()` and `loadEnvFromFile()` functions as env parsers, in `utils.c/h`.
- Added `loadEnvFromFile()` function in `main.c` to load env file's data into a struct before initiation.
- Added commented code in `admin.c` to replace visible configPass variable with the parser function.


## 🗞️ <font color="#e36c09">Nov 23, 2025 - Sunday</font>
#### [Uday](https://github.com/udaysh134)
- Updated `activity-records.md` with Nov 22, 2025 discussion and tasks, highlighting deadlines for all.
- Corrected Nov 21st, 2025 dev-report entry by changing the day from Wednesday to Friday.


## 🗞️ <font color="#e36c09">Nov 21, 2025 - Friday</font>
#### [Uday](https://github.com/udaysh134)
- Updated `activity-records.md` with Nov 21, 2025 discussion summary and task list.


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