## 🗓️ <font color="#e36c09">Nov 27, 2025 - - - - - - - - ></font>
### <font color="#fac08f">Discussion 10 :</font>
- Walked through the updated structure of `user.c` and explained why the changes were necessary.
- Created flowcharts and visually broke down how the code has been flowing so far, and how it will progress going forward.
- Discussed the upcoming “User Panel”, its options, and the functions behind them (like `createBot()` and `accessBots(...)` functions).
- Talked about the planned structure of `bot.c` and how it will integrate with `user.c`.
- Outlined the upcoming `data.c` module with functions like `view()`, `add()`, `edit()`, and `delete()`.
- Revisited code modularity and how everything stays clean and organized, using `launch.c`, `admin.c`, and `user.c` (with its sub-functions) as examples.
### <font color="#fac08f">Tasks :</font>
- Finish watching the latest discussion video by the end of the day.
- Get comfortable with the code structure, using the flowcharts as optional visual support for both the team and the general public.


######
## 🗓️ <font color="#e36c09">Nov 22, 2025 - - - - - - - - ></font>
### <font color="#fac08f">Discussion 9 :</font>
- Set clear deadlines for each member based on their assigned tasks.
- Talked about an important teamwork mindset : stepping in for someone during their absence should feel like responsibility, not burden.
### <font color="#fac08f">Tasks :</font>
- **Frontend :** Simplify the main page by removing the large Fluix text and aligning the layout more closely with the mockups. Apply a blue-accent theme (either dark or light), add a navigation bar with _Home, Features, Pricing, About,_ and _User_, and create separate HTML pages for the remaining sections.
- Deadline for frontend's tasks is Nov 26th, 2025.
- **Backend :** Finish the previously discussed `.env` parser function by tomorrow (November 23rd, 2025). Finalize the structure of `user.c` before November 26th, 2025 - this includes completing both `optSignIn()` and `optSignUp()` functions.
- Completion of `user.c` will allow work to proceed to `bot.c`, so it is required before moving forward.


######
## 🗓️ <font color="#e36c09">Nov 21, 2025 - - - - - - - - ></font>
### <font color="#fac08f">Discussion 8 :</font>
- From now on, all discussions will be one-way updates from my side ([Uday](https://github.com/udaysh134)) through recorded videos. Any counterpoints, questions, opinions, or concerns from team members must be shared in the group chat.
- This shift is happening because meetings haven’t been a viable option, and not everyone has always been able to join in.
- All team or project-related discussions must happen only in the WhatsApp group. Personal DMs won’t count unless there’s an exception.
- This ensures we maintain clear records of everyone’s input, especially since there won’t be any live meetings going forward.
- A new “Rep Board” system will be established by me ([Uday](https://github.com/udaysh134)), followed by a public “Leaderboard.” This is being done for accountability and motivation and also for a clean shift of responsibilities, if that ever happens in future.
- Once active, the Leaderboard (based on private reps from the project lead) will be updated every weekend.
- Shared upcoming plans and walked through Fluix’s system in more detail.
- Talked about the inclusion of `/packages` folder inside `src/backend/` and why it was needed.
- Reviewed the team’s progress and made it clear that lack of output will have consequences.
### <font color="#fac08f">Tasks :</font>
- The team should aim to release Fluix v0.2.0 before the screening session in college.
- Frontend team (including [Japnoor](https://github.com/kaurjapnoor60-max) and [Kashish](https://github.com/kash-12)) will create new HTML pages. Focus only on static UI for now - no animations or dynamic flow yet.
- The UI must follow the mockups already provided in the main README.
- All frontend members must use an indentation size of 4 spaces to keep HTML and CSS consistent across the project.
- Backend’s first task is to implement a `.env` parser in `utils.c` for easier access to environment variables.
- Backend also needs to continue building the `isUser()` function, which depends on completing `optSignIn()` and `optSignUp()`.
- Completion of `optSignIn()` and `optSignUp()` will allow the workflow to be redirected into another file, `bot.c` to continue building the whole system.


######
## 🗓️ <font color="#e36c09">Oct 12, 2025 - - - - - - - - ></font>
### <font color="#fac08f">Discussion 7 :</font>
- Started the discussion by making everyone aware that we won't be getting extra time in our college hours, so we have to manage this ourselves solely, at least until the screening session.
- Shared my ([Uday](https://github.com/udaysh134)'s) progress report and outlined the frontend's current focus should be on visuals (HTML and CSS) and not logic (JS) for now.
- Reaffirmed the "temporary" nature of the current backend–frontend linkage system.
- Briefly discussed professional `JSON` data handling for Retrieval Augmentation Generation with vectors and why it’s not feasible yet.
- Reviewed all members’ progress, with emphasis on backend updates.
- Explained more about the structure of `JSON`'s data storing system and tried answering some queries from the backend team.
- Finalized that search functionality will remain linear for now.
- Discussed and discarded the idea of a “recycle” feature for deleted user queries.
- Addressed [Chirag](https://github.com/chirag88533)’s limited input and lack of communication.
### <font color="#fac08f">Tasks :</font>
- Begin presentation prep after Oct 20th 2025, focusing on the Screening Session.
- Frontend team is expected to demonstrate visible progress, focusing on visuals for now.
- Backend team is expected to finalize core functionalities - Directory navigation, User creation, and Question registration (or equivalent), by **Thursday** - Oct 16, 2025.
- All members must join meetings on time to maintain consistency and progress next time onwards.


######
## 🗓️ <font color="#e36c09">Oct 08, 2025 - - - - - - - - ></font>
### <font color="#fac08f">Discussion 6 :</font>
- [Yazdaan](https://github.com/SenorDan031) will now oversee all activities as the lead within the backend unit, while I ([Uday](https://github.com/udaysh134)) will focus primarily on the frontend. This decision was made to ensure balanced workload distribution.
- Team members were reminded to log all the changes they make (regardless of their significance) in the `dev-reports.md` file within the repository.
- Presentation aspects are not a priority at this stage, the focus should remain on building core functionality before moving on to visuals.
### <font color="#fac08f">Tasks :</font>
- The backend team was reminded to implement a `.env` parser function in C, as it will be useful for future development.
- The backend team is expected to show some ground level progress on the project by the end of the current week.


######
## 🗓️ <font color="#e36c09">Oct 07, 2025 - - - - - - - - ></font>
### <font color="#fac08f">Discussion 5 :</font>
- Not everybody was present but the session proved to be productive as first, [Japnoor](https://github.com/kaurjapnoor60-max) and then [Yazdaan](https://github.com/SenorDan031) joined in with Me ([Uday](https://github.com/udaysh134)). Had a good discussion about the current progress and future direction of the project.
- Clarified topics like the new repo directory structure, header files, GCC commands, and the Makefile setup through Q&A.
### <font color="#fac08f">Tasks :</font>
- N/A


######
## 🗓️ <font color="#e36c09">Oct 05, 2025 - - - - - - - - ></font>
### <font color="#fac08f">Discussion :</font>
- N/A
### <font color="#fac08f">Tasks :</font>
- Learn how to Create, Manage and Use local header files, now necessary to understand the functioning and execution of main program.
- Learn how to compile multiple files (including header files) and get comfortable with basic GCC commands.
- Understand `Makefiles` and how they work, now necessary to match the pace of the project's progress.
- Create a function to extract and parse data from `.env` files. Function creation is expected to be done inside `utils.c` file with proper section division.
- Extend the functionality of `admin.c` and `user.c` to further make progress towards the goal of the project.


######
## 🗓️ <font color="#e36c09">Oct 01, 2025 - - - - - - - - ></font>
### <font color="#fac08f">Discussion 4 :</font>
- Finalized which main C file will continue and how other important functions will be created and used later, using header files.
- Introduced `.env` files with their necessity and talked about `.json` files and their structure & functioning and how they're going to store data provided by users + a little on how scoring algorithm will be put in place to find the closest matching question, to display correct answer - all using tags.
- Discussed and allotted work on how backend team (including [Yazdaan](https://github.com/SenorDan031), [Manikant](https://github.com/manikant12aggi) and [Chirag](https://github.com/chirag88533)) must start working on the backend structure, the whole project is relying on. Which includes - creating important functions globally for the project and working on file creation > updation > deletion, all using C.
- Visually discussed what our User DB's structure is going to look like - how the `.json` files inside folders, which are further inside other folders are going to be stored and work all together.
### <font color="#fac08f">Tasks :</font>
- I ([Uday](https://github.com/udaysh134)) will be focusing on the management and documentation part of the project + building a working UI prototype for presentation using Figma later.
- [Manikant](https://github.com/manikant12aggi) and [Chirag](https://github.com/chirag88533) will be coordinating together in making important re-usable functions for the project using header files (with `.h` extension).
- [Yazdaan](https://github.com/SenorDan031) will majorly be working on creating prototypes which are important for the project's core idea of - Feeding the information > Amending it accordingly > Using that information to provide answers.
- (For all members) Learn what JSON files are and how to manipulate data stored in them, using C.
- Add your names on your GitHub profiles for recognition and consistency (changing usernames is totally up to you).


######
## 🗓️ <font color="#e36c09">Sep 30, 2025 - - - - - - - - ></font>
### <font color="#fac08f">Discussion :</font>
- N/A
### <font color="#fac08f">Tasks :</font>
- Create code-snippet file locally in VSC by following instructions provided in the new added snippet file from the project repo.


######
## 🗓️ <font color="#e36c09">Sep 29, 2025 - - - - - - - - ></font>
### <font color="#fac08f">Discussion 3 :</font>
- Brought up more clarity on what we really have to do and how to exactly start, including working with header files and multiple functions.
- Had a session on integration of script functionality we're planning for future with our product.
- Talked about Frontend's development including design prototypes.
### <font color="#fac08f">Tasks :</font>
- Start working and coding on whatever functionality whoever can, with their limited time.
- Don't wait for instructions on UI or design prototype for Frontend, start working.
- Backend development should now begin asap, we at least need a functioning prototype.


######
## 🗓️ <font color="#e36c09">Sep 28, 2025 - - - - - - - - ></font>
### <font color="#fac08f">Discussion 2 :</font>
- Introduced the core concept of real code we're about to do, the plan we'll be working on to actually start.
### <font color="#fac08f">Tasks :</font>
- Understand the logic behind the functioning of main concept of the project, to actually initialize working on it.


######
## 🗓️ <font color="#e36c09">Sep 27, 2025 - - - - - - - - ></font>
### <font color="#fac08f">Discussion 1 :</font>
- Assigned roles for all the members of the team. Divided the team of six into 2 equal sub-teams of frontend.
### <font color="#fac08f">Tasks :</font>
- Learn GitHub and understand it's core concepts, making team coordination better for all.