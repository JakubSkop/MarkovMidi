#pragma once

#include <functional>
#include <memory>
#include <chrono>

class MarkovState;

using statePtr = std::shared_ptr<MarkovState>;

struct PercentageProbability{
    unsigned char value;
    PercentageProbability(unsigned char somePercentage);
    operator int() const;
};

class MarkovState{
    public:
        void Execute();
        void CheckProb();
        statePtr Advance();
        void AddNextState(statePtr someState, PercentageProbability prob);
        MarkovState(std::function<void()> callable);

    private:
        std::function<void()> callback;
        std::vector<statePtr> nextStates;
        std::vector<PercentageProbability> probabilities;

};

class MarkovChain{
    public:
        void Advance();
        virtual void Initialize(std::vector<statePtr> states) = 0;
        statePtr GetCurrentState();
        void SetCurrentState(statePtr state);

    private:
        statePtr currentState;

};  

class Markov1: public MarkovChain{
    public:
        void Initialize(std::vector<statePtr> states) override;

};

class Markov2: public MarkovChain{
    public:
        void Initialize(std::vector<statePtr> states) override;

};

class FourStateLoop: public MarkovChain{
    public:
        void Initialize(std::vector<statePtr> states) override;

};