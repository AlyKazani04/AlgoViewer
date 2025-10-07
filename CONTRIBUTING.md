# 🧩 Contributing Guidelines

Thank you for your interest in contributing to the Sorting Algorithm Visualizer project!
To keep our workflow clean, efficient, and consistent across the team, please follow the steps below before making any contributions.

## 📦 1. Clone the Repository

Start by cloning the project to your local workstation:

```
git clone https://github.com/AlyKazani04/AlgoViewer.git
cd <sorting-visualizer-repo>
```

🔹 Note: Do not make changes directly on the main branch.

## 🌱 2. Create a New Branch

Before you start working on a new feature, bug fix, or improvement, create a new branch from main:

```
git checkout main
git pull origin main
git checkout -b feature/<short-description>
```

Examples:

```
feature/add-bubble-sort

bugfix/fix-visual-glitch

refactor/improve-ui
```

## 🧠 3. Make Your Changes

Implement your feature or fix.
Try to keep commits small and meaningful — they should represent a single logical change.

```
git add .
git commit -m "Add quick sort visualization"
```


💡 Follow conventional commit messages whenever possible.

## 🔍 4. Keep Your Branch Updated

Before creating a pull request, make sure your branch is up to date with main:

```
git fetch origin
git merge origin/main
```

If there are merge conflicts, resolve them locally before pushing.

## 🚀 5. Push and Create a Pull Request (PR)

When you’re ready to share your work:

```
git push origin feature/<short-description>
```

Then go to the repository on GitHub and open a Pull Request to merge your branch into main.

## ✅ Pull Request Checklist

1. The code compiles and runs without errors.

2. The changes are tested (if applicable).

3. Code style and formatting follow project conventions.

4. The PR description clearly explains what was changed and why.

> ⚠️ Do not merge directly into main.
All changes must go through a PR and be reviewed first.

## 💬 6. Code Reviews

Another team member will review your PR.
If changes are requested:

Make the updates on your same branch.

Push again — the PR will automatically update.

We value respectful, constructive feedback and clear communication.

## 🧹 7. After Merging

Once your PR is approved and merged:

You can safely delete your feature branch (both locally and remotely):

```
git branch -d feature/<short-description>
git push origin --delete feature/<short-description>
```

## 🧭 Summary
| Action | Command |
|:--------|:----------|
| Clone repo | `git clone <repo-url>` |
| Create branch | `git checkout -b feature/<desc>` |
| Commit changes | `git commit -m "<message>"` |
| Update with main | `git merge origin/main` |
| Push branch | `git push origin feature/<desc>` |
| Open PR | via GitHub |

### 🫱🏼‍🫲🏽 Thanks for Contributing!

