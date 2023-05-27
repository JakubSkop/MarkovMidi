#include "Markov.hpp"
#include <stdexcept>
#include <numeric>
#include "randomness.hpp"

PercentageProbability::PercentageProbability(unsigned char somePercentage){
    if (somePercentage<0 || somePercentage>100){
        throw std::invalid_argument( "Probability not between 0 and 100" );
    } else {
        value = somePercentage;
    };  
}

PercentageProbability::operator int() const{
    return value;
};

using statePtr = std::shared_ptr<MarkovState>;

MarkovState::MarkovState(std::function<void()> callable){
    callback = callable;
    nextStates = {};
    probabilities = {};
};

void MarkovState::Execute(){
    callback();
}

void MarkovState::CheckProb(){
    int sum = std::reduce(probabilities.begin(), probabilities.end(), 0);
    if (sum > 100){
        throw std::domain_error("Probabilities summing to >100");
    };
}

void MarkovState::AddNextState(statePtr someState, PercentageProbability prob){
    probabilities.push_back(prob);
    nextStates.push_back(someState);
    CheckProb();
}

statePtr MarkovState::Advance(){
    std::uniform_int_distribution<int> distribution(0, 99);
    int random_num = distribution(rng);
    int cum = 0;
    for(int i = 0; i<probabilities.size(); i++){
        if(cum <= random_num && random_num < cum+probabilities[i]){
            return nextStates[i];
        };
        cum += probabilities[i];
    };
    throw std::domain_error("Probabilities summing to >100");
}




statePtr MarkovChain::GetCurrentState(){
    return currentState;
};

void MarkovChain::SetCurrentState(statePtr state){
    currentState = state;
};

void MarkovChain::Advance(){
    currentState->Execute();
    currentState = currentState->Advance();
};

void Markov1::Initialize(std::vector<statePtr> states){
    statePtr  s1 = states[0];
    statePtr  s2 = states[1];
    statePtr  s3 = states[2];
    statePtr  s4 = states[3];
    statePtr  s5 = states[4];

    s1->AddNextState(s2,60);
    s1->AddNextState(s3,20);
    s1->AddNextState(s4,10);
    s1->AddNextState(s1,10);

    s2->AddNextState(s3,70);
    s2->AddNextState(s4,30);

    s3->AddNextState(s4,40);
    s3->AddNextState(s1,30);
    s3->AddNextState(s5,30);

    s4->AddNextState(s5,50);
    s4->AddNextState(s2,50);

    s5->AddNextState(s1,50);
    s5->AddNextState(s4,50);

    SetCurrentState(s1);
};

void Markov2::Initialize(std::vector<statePtr> states){
    statePtr  s1 = states[0];
    statePtr  s2 = states[1];
    statePtr  s3 = states[2];
    statePtr  s4 = states[3];
    statePtr  s5 = states[4];

    s1->AddNextState(s2,70);
    s1->AddNextState(s3,0);
    s1->AddNextState(s4,30);
    s1->AddNextState(s1,0);

    s2->AddNextState(s1,50);
    s2->AddNextState(s5,50);

    s3->AddNextState(s3,30);
    s3->AddNextState(s1,30);
    s3->AddNextState(s2,40);

    s4->AddNextState(s5,90);
    s4->AddNextState(s4,10);

    s5->AddNextState(s3,70);
    s5->AddNextState(s5,30);

    SetCurrentState(s2);
};

void FourStateLoop::Initialize(std::vector<statePtr> states){
    statePtr  s1 = states[0];
    statePtr  s2 = states[1];
    statePtr  s3 = states[2];
    statePtr  s4 = states[3];

    s1->AddNextState(s2,100);
    s2->AddNextState(s3,100);
    s3->AddNextState(s4,100);
    s4->AddNextState(s1,100);

    SetCurrentState(s1);
};